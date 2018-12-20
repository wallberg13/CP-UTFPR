package com.example.sir_berg.prova01_dispositivos;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class AlturaActivity extends AppCompatActivity {

    private EditText etAltura;
    private String peso = ""; // Acumulado :-(

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_altura);

        Intent i = getIntent();
        peso = i.getStringExtra("peso");

        etAltura = (EditText) findViewById(R.id.etAltura);
    }


    public void btAlturaProxOnClick(View view) {
        String aux = etAltura.getText().toString();
        if(aux.equals("")) {
            etAltura.setError("Altura nao pode ser vazia");
            etAltura.requestFocus();
        }else{
            Intent i = new Intent(this, SexoActivity.class);

            i.putExtra("peso", peso);
            i.putExtra("altura", aux);

            startActivity(i);
            finish();
        }
    }
}
