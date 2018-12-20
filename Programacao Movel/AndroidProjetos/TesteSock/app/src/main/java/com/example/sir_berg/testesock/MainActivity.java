package com.example.sir_berg.testesock;

import android.content.Intent;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private Button btConectar;
    private Button btEnviar;
    private EditText etTexto;
    private EditText etIpServer;
    private TextView tvLogServer;

    private int porta = 12345;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btEnviar = (Button) findViewById(R.id.btEnviar);
        etTexto = (EditText) findViewById(R.id.etMensagem);
        etIpServer = (EditText) findViewById(R.id.etIpServer);
        tvLogServer = (TextView) findViewById(R.id.tvRespostaServer);

        etIpServer.setText("172.20.220.<UTF>");

    }

    public EditText getEtTexto() {
        return etTexto;
    }

    public void btEnviarOnClick(View view){
        /**
         * Cria o Cliente TCP como uma tarefa em background.
         **/
        Thread threadClient = new Thread(new RunClient(etIpServer.getText().toString(), this.porta, this, "ma "+etTexto.getText().toString()));
        threadClient.start();

    }

    /**
     * Indo para a intent de configuraçao.
     * So para fins de teste.
     **/
    public void btConfiguracaoOnClick(View view){

        Intent i = new Intent(this, Configuracao.class);
        i.putExtra("ip", etIpServer.getText().toString());
        i.putExtra("porta", this.porta);
        startActivityForResult(i, 0);

    }

    public void setTvLogServer(String str){
        tvLogServer.setText(tvLogServer.getText().toString()+"\n"+str);
        Toast.makeText(this, "Novo dado na coleira", Toast.LENGTH_SHORT).show();
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        String hora;
        if(data != null){
            if(resultCode == 0){
                hora = data.getStringExtra("hora");
                setTvLogServer(hora);
            }
        }

    }
}
