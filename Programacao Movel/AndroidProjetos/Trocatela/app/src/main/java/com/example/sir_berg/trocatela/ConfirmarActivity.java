package com.example.sir_berg.trocatela;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class ConfirmarActivity extends AppCompatActivity {

    private TextView tvCod;
    private TextView tvQtd;
    private TextView tvVal;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_confirmar);

        tvCod = (TextView) findViewById( R.id.tvCod );
        tvQtd = (TextView) findViewById( R.id.tvQtd );
        tvVal = (TextView) findViewById( R.id.tvValor );

        Intent i = getIntent();
        tvVal.setText(i.getStringExtra("valor"));
        tvQtd.setText(i.getStringExtra("qtd"));
        tvCod.setText(i.getStringExtra("cod"));
    }


    public void btConfirmarOnClick(View view) {
        Toast.makeText(this, "Op. Indisponivel no Momento", Toast.LENGTH_LONG).show();
    }
}
