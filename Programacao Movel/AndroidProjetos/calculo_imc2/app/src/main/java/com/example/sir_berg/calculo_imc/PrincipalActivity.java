package com.example.sir_berg.calculo_imc;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import java.lang.Math;
import java.text.DecimalFormat;

public class PrincipalActivity extends Activity {

    private EditText etPeso;
    private EditText etAltura;
    private Button btCalcular;
    private Button btLimpar;
    private TextView tvImcCalc;


    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_principal); // Colocando na tela para o usuario ver

        etPeso = (EditText) findViewById( R.id.etPeso );
        etAltura = (EditText) findViewById( R.id.etAltura );
        btCalcular = (Button) findViewById( R.id.btCalcular );
        btLimpar = (Button) findViewById( R.id.btLimpar );
        tvImcCalc = (TextView) findViewById( R.id.tvImcCalc);

        /**
         *  Criando uma classe interna anônima.
         **/
        btLimpar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                btLimparOnClick();
            }
        });

        btLimpar.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View view) {
                Toast.makeText(PrincipalActivity.this,
                        "Limpa a tela!",
                        Toast.LENGTH_LONG).show();

                return true; // Não executa o evento de clique que vem logo em seguida.
            }
        });

        btCalcular.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                btCalcularOnClick();
            }
        });

        btCalcular.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View view) {
                Toast.makeText(PrincipalActivity.this,
                                "Calcular o IMC",
                                Toast.LENGTH_LONG).show();

                return true;
            }
        });

    }

    /**
     * Método para tratar o evento de Click do Botão de Limpar.
     **/
    private void btLimparOnClick(){
        Toast.makeText(PrincipalActivity.this,
                "Limpando Campos",
                Toast.LENGTH_SHORT).show();
        etPeso.setText("");
        etAltura.setText("");
        tvImcCalc.setText("0.0");
        etPeso.requestFocus();
    }

    /**
     * Método para tratar o evento de Click do Botão de Calcular.
     **/
    private void btCalcularOnClick(){

        // Entrada
        if(etPeso.getText().toString().equals("")){
            etPeso.setError("Campo peso deve ser preenchido");
            etPeso.requestFocus();
            return;
        }

        if(etAltura.getText().toString().equals("")){
            etAltura.setError("Campo altura deve ser preenchido");
            etAltura.requestFocus();
            return;
        }

        double peso = Double.parseDouble(etPeso.getText().toString());
        double altura = Double.parseDouble(etAltura.getText().toString());

        // Processamento
        double imc = peso / Math.pow(altura, 2);

        // Saída
        DecimalFormat formatador = new DecimalFormat("#.##");
        tvImcCalc.setText(formatador.format(imc));

    }
}
