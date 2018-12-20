package com.example.sir_berg.prova01_dispositivos;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class SexoActivity extends AppCompatActivity {

    private EditText etSexo;
    private String peso;
    private String altura;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sexo);

        Intent i = getIntent();

        peso = i.getStringExtra("peso");
        altura = i.getStringExtra("altura");

        etSexo = (EditText) findViewById(R.id.etSexo);
    }

    public void btSexoProxOnClick(View view) {
        String aux = etSexo.getText().toString();
        if(aux.equals("")){
            etSexo.setError("Digite o Sexo!!");
            etSexo.requestFocus();
        }else{
            aux = aux.toUpperCase();
            if(!aux.equals("M") && !aux.equals("F")){
                etSexo.setError("Digite M ou F!!");
            }else{
                Intent i = new Intent(this, IdadeActivity.class);

                i.putExtra("peso", peso);
                i.putExtra("altura", altura);
                i.putExtra("sexo", aux);

                startActivity(i);
                finish();
            }
        }
    }
}
