package prova02.wallberg.br.com.prova02.DAO;

import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import prova02.wallberg.br.com.prova02.Entidade.Descricoes;
import prova02.wallberg.br.com.prova02.Factory.ConexaoFactory;

public class DescricoesDAO {
    private SQLiteDatabase db;

    public DescricoesDAO(Activity context){
        db = ConexaoFactory.getConnection(context);
    }

    public void incluir(Descricoes de){

        ContentValues registro = new ContentValues();

        registro.put("descricao", de.getDescricao());
        registro.put("tipo", de.getTipo());

        // Descricao é unique, em caso de erro é -1, mas o erro nao é lido
        db.insert("descricoes", null, registro);
    }

    public String[] listarDescricao(String tipo){
        Cursor cursor = db.query("descricoes",new String[] {"descricao"}, "tipo = ?", new String[] {tipo}, null, null, null);

        if(cursor.getCount() == 0)
            return null;

        String reg[] = new String[ cursor.getCount() ];

        // Tranforma os dados recebidos do cursor em String.
        // Esses dados serao jogados para um vetor de string, que sera jogado para um ArrayAdapter.
        int i = 0;
        while( cursor.moveToNext() ){
            reg[i] = cursor.getString(cursor.getColumnIndex("descricao"));
            i++;
        }

        return reg;
    }
}
