package com.example.sir_berg.teste;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private TextView tvHello;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tvHello = (TextView) findViewById(R.id.tvHello);

    }

    public void btTextoOnClick(View view) {
        Toast.makeText(this, "Buceta e bom pra caralho!!", Toast.LENGTH_SHORT).show();
        tvHello.setText("Pintaoooooo!!!");
    }
}
