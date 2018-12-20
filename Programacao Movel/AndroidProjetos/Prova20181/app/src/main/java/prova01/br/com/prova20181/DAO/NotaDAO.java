package prova01.br.com.prova20181.DAO;

import android.app.Activity;
import android.database.sqlite.SQLiteDatabase;

import prova01.br.com.prova20181.Factory.ConexaoFactory;

public class NotaDAO {
    private SQLiteDatabase db;

    public NotaDAO(Activity context){
        db = ConexaoFactory.getConnection(context);
    }
}
