package prova01.br.com.prova20181.Factory;

import android.app.Activity;
import android.content.Context;
import android.database.sqlite.SQLiteDatabase;

/**
 * Classe que utiliza de métodos estaticos para
 * poder fazer acesso ao banco e fornecer para todos os usuários.
 **/
public class ConexaoFactory {

    public static SQLiteDatabase db;

    public static SQLiteDatabase getConnection( Activity context ){

        if(db == null){
            // Criando a conexão para a primeira activity que executar essa funcao.
            db = context.openOrCreateDatabase("banco", Context.MODE_PRIVATE, null);

            // Criando as tabelas de disciplina e nota.
            db.execSQL("CREATE TABLE IF NOT EXISTS disciplina(_id INTEGER PRIMARY KEY AUTOINCREMENT, nome TEXT                 )");
            db.execSQL("CREATE TABLE IF NOT EXISTS       nota(_id INTEGER PRIMARY KEY AUTOINCREMENT, disciplina TEXT, nota TEXT)");
        }

        return db;
    }

}
