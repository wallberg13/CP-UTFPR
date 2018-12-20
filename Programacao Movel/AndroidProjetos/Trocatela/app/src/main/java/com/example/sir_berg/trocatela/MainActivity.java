package com.example.sir_berg.trocatela;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void btLancamentoOnClick(View view) {
        Intent i = new Intent(this, LancamentoActivity.class );
        startActivity(i);
    }

    public void btSairOnClick(View view) {
        finish();
    }
}
