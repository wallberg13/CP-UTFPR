package com.example.sir_berg.prova01_dispositivos;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import java.text.DecimalFormat;

public class ResultadoActivity extends AppCompatActivity {

    private Double peso;
    private Integer altura;
    private char sexo;
    private Integer idade;
    private Integer cod;
    private TaxaMetaBasal tmb;

    private TextView tvResultado;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_resultado);

        tvResultado = (TextView) findViewById(R.id.tvResultado);

        Intent i = getIntent();

        peso = Double.valueOf(i.getStringExtra("peso"));
        altura = Integer.valueOf(i.getStringExtra("altura"));
        sexo = i.getStringExtra("sexo").charAt(0);
        idade = Integer.valueOf(i.getStringExtra("idade"));
        cod = Integer.valueOf(i.getStringExtra("codigo"));

        tmb = new TaxaMetaBasal(peso, altura, sexo, idade, cod);

        DecimalFormat decimalFormat = new DecimalFormat("#.##");
        tvResultado.setText(String.valueOf(decimalFormat.format(tmb.calc())) + " KCal");
    }

    public void btSairOnClick(View view) {
        System.exit(0);
    }
}
