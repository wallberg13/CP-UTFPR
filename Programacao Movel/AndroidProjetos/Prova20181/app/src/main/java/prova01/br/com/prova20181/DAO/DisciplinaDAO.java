package prova01.br.com.prova20181.DAO;

import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import prova01.br.com.prova20181.Entidade.Disciplina;
import prova01.br.com.prova20181.Factory.ConexaoFactory;

public class DisciplinaDAO {

    private SQLiteDatabase db;

    public DisciplinaDAO(Activity context){
        db = ConexaoFactory.getConnection(context);
    }

    public void incluir(Disciplina disciplina){
        ContentValues registro = new ContentValues();
        registro.put("nome", disciplina.getNome());

        db.insert("disciplina", null, registro);
    }

    public String[] montarListaDisciplina() {
        Cursor c = db.query( "disciplina", new String[] {"nome"}, null, null, null, null, null );

        if(c.getCount() == 0)
            return null;

        String registros[] = new String[ c.getCount() ];

        int i = 0;
        while ( c.moveToNext() ) {
            String nome = c.getString( c.getColumnIndex( "nome" ) );
            registros[i] = nome;
            i++;
        }

        return registros;
    }
}
