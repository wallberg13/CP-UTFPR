package com.example.sir_berg.usandolistas;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.ListView;
import android.widget.Spinner;

public class PrincipalActivity extends AppCompatActivity {

    private ListView lvLista;
    private AutoCompleteTextView acCidade;
    private Spinner spEstados;


    String elementos[] = {"Pato Branco", "Pato Bragado", "Mariopolois", "Maringa", "Vere", "Marialva", "Coronel Vivida", "Vitorino"};
    String estados[] = {"Parana", "Santa Catarina", "Rio Grande do Sul"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_principal);

        //lvLista = (ListView) findViewById(R.id.lvLista);
        acCidade = (AutoCompleteTextView) findViewById( R.id.acCidade );
        spEstados = (Spinner) findViewById( R.id.spEstado );

        ArrayAdapter adapter = new ArrayAdapter(this, android.R.layout.simple_list_item_1, elementos);
        ArrayAdapter adapter2 = new ArrayAdapter(this, android.R.layout.simple_list_item_1, estados);

        acCidade.setThreshold( 1 );
        acCidade.setAdapter( adapter );

        spEstados.setAdapter(adapter2);
    }
}
