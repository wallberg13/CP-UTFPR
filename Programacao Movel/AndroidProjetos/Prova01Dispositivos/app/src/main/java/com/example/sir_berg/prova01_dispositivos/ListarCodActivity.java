package com.example.sir_berg.prova01_dispositivos;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Toast;

public class ListarCodActivity extends AppCompatActivity {

    private ListView lvCodigos;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_listar_cod);

        lvCodigos = (ListView) findViewById(R.id.lvCodigos);
        lvCodigos.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int pos, long l) {
                lvCodigoOnItemClick(pos);
            }
        });
    }

    private void lvCodigoOnItemClick(int pos){
        int cod = pos + 1;
        Intent i = getIntent();
        Toast.makeText(this, "Item selecionado: " + cod, Toast.LENGTH_SHORT).show();
        i.putExtra("codigo", cod);
        setResult(0, i);
        finish();
    }
}
