package com.example.sir_berg.prova01_dispositivos;

import android.content.Intent;
import android.os.Parcelable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class PesoActivity extends AppCompatActivity {

    private EditText etPeso;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        etPeso = (EditText) findViewById(R.id.etPeso);
    }

    public void btPesoProxOnClick(View view) {
        if(etPeso.getText().toString().equals("")){
            etPeso.setError("Campo peso deve ser preenchido!!");
            etPeso.requestFocus();
        }else{
            Intent i = new Intent(this, AlturaActivity.class);
            i.putExtra("peso",etPeso.getText().toString());
            startActivity(i);
            finish(); // Fake Sair
        }
    }
}
