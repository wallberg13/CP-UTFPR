package com.example.sir_berg.teste_bd.dao;

import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import com.example.sir_berg.teste_bd.entidade.Cadastro;
import com.example.sir_berg.teste_bd.factory.ConexaoFactory;

public class CadastroDAO {

    private SQLiteDatabase bd;

    public CadastroDAO(Activity context){

        bd = ConexaoFactory.getConnection(context);

    }

    public void incluir(Cadastro cad) {
        ContentValues registro = new ContentValues();
        registro.put("NOME", cad.getNome());
        registro.put("TELEFONE", cad.getTelefone());

        bd.insert("cadastro", null, registro);
    }

    public void alterar(Cadastro cad){

        ContentValues registro = new ContentValues();
        registro.put("NOME", cad.getNome());
        registro.put("TELEFONE", cad.getTelefone());

        bd.update("cadastro", registro, "_id = ?", new String[] {String.valueOf(cad.getCod())} );
    }

    public void excluir( int cod ){

        /**
         * Colocar os ? para diminuir os parametros que sera deletado as coisas no android.
         * O terceiro parametro é para colocar o parametro em questao.
         **/
        bd.delete("cadastro", "_id = ?", new String[] {String.valueOf(cod)});

    }

    public Cadastro pesquisar( int cod ){
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
        Cursor cursor = bd.query("cadastro",null, null, null, null, null, null);

        return cursor;
    }

}
