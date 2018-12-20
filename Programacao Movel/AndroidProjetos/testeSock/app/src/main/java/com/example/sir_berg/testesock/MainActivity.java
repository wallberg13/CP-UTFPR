package com.example.sir_berg.testesock;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class MainActivity extends AppCompatActivity {

    private Button btManda;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btManda = (Button) findViewById(R.id.btManda);


    }


    public void mandaString(String manda){
        try{
            outO.writeUTF(manda.toString());
        }catch(IOException ex){
            Toast.makeText(this, "Erro no sock", Toast.LENGTH_SHORT).show();
        }

    }

    public void btMandaAi(View view) {


    }
}

class SocketThread implements Runnable{

    private Socket sock;
    private int porta = 1080;
    private String ip = "172.20.220.247";
    private DataOutputStream outO = null;

    @Override
    public void run() {
        try{
            sock = new Socket(this.ip, this.porta);
            this.outO = new DataOutputStream(sock.getOutputStream());
        }catch (IOException ex){
            Toast.makeText(this, "Erro no Sock", Toast.LENGTH_SHORT).show();
        }
    }
}
