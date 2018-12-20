package com.example.sir_berg.trocatela;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Toast;

import java.util.List;

public class ListarActivity extends AppCompatActivity {

    private ListView lvProdutos;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_listar);

        lvProdutos = (ListView) findViewById( R.id.lvProdutos );

        lvProdutos.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int pos, long l) {
                lvProdutosOnItemClick( pos );
            }
        });
    }

    private void lvProdutosOnItemClick(int pos){
        Toast.makeText(this, "Elemento " + pos + " selecionado", Toast.LENGTH_SHORT).show();

        int cod = pos + 1;

        Intent i = getIntent();
        i.putExtra("getCod", cod); // Coloca um put no intent
        setResult(0, i); // Retorno de sucesso
        finish(); // Encerra a tela
    }
}
