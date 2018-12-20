package com.example.sir_berg.testesock;


import android.app.Activity;
import android.widget.Button;
import android.widget.Toast;

import java.io.OutputStream;
import java.io.InputStream;
import java.net.Socket;

public class ClientTCP{
    private Socket sock; // Descritor de socket.
    private OutputStream out; // Saida de bytes
    private InputStream in;

    public ClientTCP(String ip, int porta, final Activity context){
        try {
            this.sock = new Socket(ip, porta);
            this.out = sock.getOutputStream();
            this.in  = sock.getInputStream();
        }catch (Exception ex) {
            context.runOnUiThread( new Thread() {
                public void run() {
                    Toast.makeText(context, "Deu erro desconhecido!!", Toast.LENGTH_SHORT).show();
                }
            });
        }
    }

    public String ClientSendReq(String requisicao, final Activity context){

        String resp = "";

        try {
            this.out.write(requisicao.getBytes()); // Manda a requisicao.

            int bytesRead;

            while(( bytesRead = in.read() ) != -1){
                resp += (char) bytesRead;
            }

        }catch (Exception ex){

            context.runOnUiThread( new Thread(){
                public void run(){
                    Toast.makeText(context, "Deu erro ao enviar!!", Toast.LENGTH_SHORT).show();
                }
            });
        }

        return resp;
    }

    public void ClientClose(final Activity context){
        try {
            this.sock.close();
        }catch (Exception e){
            context.runOnUiThread( new Thread() {
                public void run() {
                    Toast.makeText(context, "Deu erro desconhecido!!", Toast.LENGTH_SHORT).show();
                }
            });
        }
    }

}
