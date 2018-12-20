package prova02.wallberg.br.com.prova02.Factory;

import android.app.Activity;
import android.content.Context;
import android.database.sqlite.SQLiteDatabase;

public class ConexaoFactory {

    public static SQLiteDatabase db;

    public static SQLiteDatabase getConnection(Activity context){

        if(db == null){

            db = context.openOrCreateDatabase("banco", Context.MODE_PRIVATE, null);
            db.execSQL("CREATE TABLE IF NOT EXISTS fluxocaixa( _id INTEGER PRIMARY KEY AUTOINCREMENT, tipo TEXT, descricao TEXT, valor TEXT)");
            db.execSQL("CREATE TABLE IF NOT EXISTS descricoes( _id INTEGER PRIMARY KEY AUTOINCREMENT, tipo TEXT, descricao TEXT UNIQUE)");

        }

        return db;
    }

}
