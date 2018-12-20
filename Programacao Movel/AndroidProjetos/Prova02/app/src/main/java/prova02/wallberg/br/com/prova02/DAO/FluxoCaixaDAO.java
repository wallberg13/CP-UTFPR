package prova02.wallberg.br.com.prova02.DAO;

import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import prova02.wallberg.br.com.prova02.Entidade.FluxoCaixa;
import prova02.wallberg.br.com.prova02.Factory.ConexaoFactory;

public class FluxoCaixaDAO {

    private SQLiteDatabase db;

    public FluxoCaixaDAO(Activity context){
        db = ConexaoFactory.getConnection(context);
    }

    public void incluir(FluxoCaixa fc){
        ContentValues registro = new ContentValues();
        registro.put("tipo", fc.getTipo());
        registro.put("descricao", fc.getDescricao());
        registro.put("valor", String.valueOf(fc.getValor()));

        db.insert("fluxocaixa", null, registro);
    }

    public double calculaTotal(String tipo){
        Cursor cursor = db.query("fluxocaixa", new String[] {"valor"}, "tipo = ?", new String[] {tipo}, null, null, null);

        Double sum = 0.0;

        while(cursor.moveToNext()){
            sum += Double.valueOf( cursor.getString( cursor.getColumnIndex("valor")) );
        }

        return sum;
    }

}
