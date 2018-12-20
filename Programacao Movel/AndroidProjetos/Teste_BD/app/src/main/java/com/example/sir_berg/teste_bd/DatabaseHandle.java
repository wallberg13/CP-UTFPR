package com.example.sir_berg.teste_bd;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import com.example.sir_berg.teste_bd.entidade.Cadastro;

public class DatabaseHandle extends SQLiteOpenHelper {

    private static final int DATABASE_VERSION = 1;
    private static final String DATABASE_NAME = "banco";

    public DatabaseHandle( Context c ){
        super(c, DATABASE_NAME,  null, DATABASE_VERSION);
    }

    @Override
    public void onCreate( SQLiteDatabase bd ) {
        bd.execSQL("CREATE TABLE IF NOT EXISTS cadastro( _id INTEGER PRIMARY KEY AUTOINCREMENT, NOME TEXT, TELEFONE TEXT)");
    }

    @Override
    public void onUpgrade(SQLiteDatabase bd, int oldVersion, int newVersion) {
        bd.execSQL( "DROP TABLE IF EXISTS " + DATABASE_NAME);
        onCreate( bd );
    }

    public void incluir( Cadastro cad ){

        SQLiteDatabase bd = getWritableDatabase();

        ContentValues registro = new ContentValues();
        registro.put("NOME", cad.getNome());
        registro.put("TELEFONE", cad.getTelefone());

        bd.insert("cadastro", null, registro);
    }

    public void alterar( Cadastro cad ){
        SQLiteDatabase bd = getWritableDatabase();

        ContentValues registro = new ContentValues();
        registro.put("NOME", cad.getNome());
        registro.put("TELEFONE", cad.getTelefone());

        bd.update("cadastro", registro, "_id = ?", new String[] {String.valueOf(cad.getCod())} );
    }

    public void excluir( int cod ){
        SQLiteDatabase bd = getWritableDatabase();

        /**
         * Colocar os ? para diminuir os parametros que sera deletado as coisas no android.
         * O terceiro parametro é para colocar o parametro em questao.
         **/
        bd.delete("cadastro", "_id = ?", new String[] {String.valueOf(cod)});
    }

    public Cadastro pesquisar( int cod ){
        SQLiteDatabase bd = getWritableDatabase();
        Cadastro cad = new Cadastro();
        Cursor registro = bd.query("cadastro", new String[] {"NOME", "TELEFONE"}, "_id = ?", new String[] { String.valueOf(cod) }, null, null, null);

        if(registro.moveToNext()){
            cad.setNome(registro.getString(registro.getColumnIndex("NOME")));
            cad.setTelefone(registro.getString(registro.getColumnIndex("TELEFONE")));
            cad.setCod(cod);
            return cad;
        }else{
            return null;
        }
    }

    public Cursor listar(){
        SQLiteDatabase bd = getWritableDatabase();

        Cursor cursor = bd.query("cadastro",null, null, null, null, null, null);

        return cursor;
    }
}
