package com.example.administrador.curioso;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;

import java.util.List;

public class ListarActivity extends AppCompatActivity {

    private ListView lvRegistros;

    private SQLiteDatabase banco;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_listar);

        lvRegistros = (ListView) findViewById(R.id.lvRegistros);

        banco = openOrCreateDatabase("banco", Context.MODE_PRIVATE, null);

        montarListPrincipal();
    }

    private void montarListPrincipal(){

        Cursor registros = banco.query("lancamento", null, null, null, null, null, null);

        String colunaBanco[] = {"descricao", "valor", "tipo"};
        int campoTela[] = {R.id.tveDescricao, R.id.tveValor, R.id.ivTipo};

        //SimpleCursorAdapter adapter = new SimpleCursorAdapter( this, R.layout.elemento_lista,
                    //registros, colunaBanco, campoTela );
        MeuAdapter adapter = new MeuAdapter(this, registros);

        lvRegistros.setAdapter( adapter );

    }
}
