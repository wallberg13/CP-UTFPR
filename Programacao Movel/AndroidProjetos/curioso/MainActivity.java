package com.example.administrador.curioso;

import android.content.ContentValues;
import android.content.Context;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private Spinner spTipo;
    private EditText etDescricao;
    private EditText etValor;

    private String tipos[] = {"Credito", "Debito"};

    private SQLiteDatabase db;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        spTipo = (Spinner) findViewById(R.id.spTipo);
        etDescricao = (EditText) findViewById(R.id.etDescricao);
        etValor = (EditText) findViewById( R.id.etValor );

        db = openOrCreateDatabase("banco", Context.MODE_PRIVATE, null);
        db.execSQL("CREATE TABLE IF NOT EXISTS lancamento(_id INTEGER PRIMARY KEY AUTOINCREMENT, descricao TEXT, valor DECIMAL, tipo TEXT)");

        ArrayAdapter tipoAdapter = new ArrayAdapter(this, android.R.layout.simple_list_item_1, tipos);
        spTipo.setAdapter(tipoAdapter);
    }

    public void btAddOnClick(View view) {
        String tipo = (String) spTipo.getItemAtPosition( spTipo.getSelectedItemPosition() );
        ContentValues registro = new ContentValues();
        registro.put("descricao", etDescricao.getText().toString());
        registro.put("valor", Double.parseDouble(etValor.getText().toString()));
        registro.put("tipo", tipo);
        db.insert("lancamento", null, registro);

        Toast.makeText(this, "Deu pra add!!", Toast.LENGTH_SHORT).show();
    }

    public void btListarOnClick(View view){
        startActivity(new Intent(this, ListarActivity.class));
    }
}
