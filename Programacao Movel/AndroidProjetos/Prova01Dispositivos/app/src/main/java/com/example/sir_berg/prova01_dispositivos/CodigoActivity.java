package com.example.sir_berg.prova01_dispositivos;

import android.content.Intent;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class CodigoActivity extends AppCompatActivity {

    private EditText etCodigo;

    private String peso;
    private String altura;
    private String sexo;
    private String idade;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_codigo);

        Intent i =  getIntent();

        peso = i.getStringExtra("peso");
        altura = i.getStringExtra("altura");
        sexo = i.getStringExtra("sexo");
        idade = i.getStringExtra("idade");

        etCodigo = (EditText) findViewById(R.id.etCodigo);
    }

    public void btPesquisarOnClick(View view) {
        Intent i = new Intent(this, ListarCodActivity.class);
        startActivityForResult(i, 1);
    }

    public void btTaxaOnClick(View view) {
        String aux = etCodigo.getText().toString();
        if(aux.equals("")){
            etCodigo.setError("O codigo deve ser preenchido!!");
            etCodigo.requestFocus();
        }else{
            Integer aux2 = Integer.valueOf(aux); // Gambiarrinha preguiçosa
            if(aux2 < 1 || aux2 > 5){
                etCodigo.setError("Valor entre 1 ~ 5!!");
                etCodigo.requestFocus();
            }else {

                Intent i = new Intent(this, ResultadoActivity.class);

                i.putExtra("peso", peso);
                i.putExtra("altura", altura);
                i.putExtra("sexo", sexo);
                i.putExtra("idade", idade);
                i.putExtra("codigo", aux);

                startActivity(i);
                finish();
            }
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {

        if(requestCode == 1){
            if(data != null){
                int cod = data.getIntExtra("codigo", 0);
                etCodigo.setText(String.valueOf(cod));
                etCodigo.requestFocus();
            }
        }

    }
}
