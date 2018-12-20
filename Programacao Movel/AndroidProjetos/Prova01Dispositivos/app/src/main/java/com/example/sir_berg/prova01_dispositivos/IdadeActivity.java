package com.example.sir_berg.prova01_dispositivos;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class IdadeActivity extends AppCompatActivity {

    private EditText etIdade;

    private String peso;
    private String altura;
    private String sexo;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_idade);

        Intent i = getIntent();

        peso = i.getStringExtra("peso");
        altura = i.getStringExtra("altura");
        sexo = i.getStringExtra("sexo");

        etIdade = (EditText) findViewById(R.id.etIdade);
    }

    public void btCodProxOnClick(View view) {
        String aux;
        aux = etIdade.getText().toString();
        if(aux.equals("")){
            etIdade.setError("Preencha a idade!!");
            etIdade.requestFocus();
        }else{
            Intent i = new Intent(this, CodigoActivity.class);

            i.putExtra("peso", peso);
            i.putExtra("altura", altura);
            i.putExtra("sexo", sexo);
            i.putExtra("idade", aux);

            startActivity(i);
            finish();
        }
    }
}
