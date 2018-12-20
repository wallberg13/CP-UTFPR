package com.example.sir_berg.teste_bd;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;

import com.example.sir_berg.teste_bd.dao.CadastroDAO;
import com.example.sir_berg.teste_bd.factory.ConexaoFactory;

/**
 * Padrão de MVC.
 **/

public class ListaCampos extends AppCompatActivity {

    private ListView lvRegistro;

    private CadastroDAO cadDao;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lista_campos);

        lvRegistro = (ListView) findViewById( R.id.lvRegistro );

        cadDao = new CadastroDAO(this);

        montarLista();
    }

    private void montarLista(){

        Cursor registro = cadDao.listar();

        String campo[] = {"NOME", "TELEFONE"};
        int id_campo[] = { android.R.id.text1, android.R.id.text2 };

        SimpleCursorAdapter adapter = new SimpleCursorAdapter( this, android.R.layout.simple_list_item_2, registro, campo, id_campo);

        lvRegistro.setAdapter(adapter);
    }
}
