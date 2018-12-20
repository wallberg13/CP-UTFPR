package com.example.sir_berg.trocatela;

import android.content.Intent;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class LancamentoActivity extends AppCompatActivity {

    private EditText etCod;
    private EditText etQtd;
    private EditText etValor;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lancamento);

        etCod = (EditText) findViewById( R.id.etCod );
        etQtd = (EditText) findViewById( R.id.etQtd );
        etValor = (EditText) findViewById( R.id.etValor );

    }

    public void btConfirmarOnClick(View view) {
        Intent i = new Intent(this, ConfirmarActivity.class );
        i.putExtra("cod", etCod.getText().toString() );
        i.putExtra("qtd", etQtd.getText().toString() );
        i.putExtra("valor", etValor.getText().toString() );
        startActivity( i );
    }

    public void btListarOnClick(View view) {
        Intent i = new Intent(this, ListarActivity.class );
        /**
         * Chama activity com um requestCode para receber o resultado.
         **/
        startActivityForResult(i, 1);

    }

    /**
     *  Para todas as telas que precisam de retorno, ira cair nessa tela.
     *  Data e a intent que parou aquela activity.
     **/
    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {

        if (requestCode == 1){
            /**
             * Tratando a resposta anterior caso apertou no botao voltar
             */
            if( data != null ){
                int cod = data.getIntExtra( "getCod", 0);
                etCod.setText(String.valueOf(cod));
                etQtd.requestFocus();
            }
        }

    }
}
