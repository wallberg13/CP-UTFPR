package com.example.sir_berg.testesock;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.ThemedSpinnerAdapter;
import android.widget.TimePicker;
import android.widget.Toast;

public class Configuracao extends AppCompatActivity {

    private TimePicker tpHora;
    private TextView tvHora;
    private int hora;
    private int minuto;
    private String horaFormatada = "";

    // Variaveis referentes ao sock
    private String ip;
    private int porta;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_configuracao);

        tpHora = (TimePicker) findViewById(R.id.tpHora);
        tvHora = (TextView) findViewById(R.id.tvHora);

        Intent i = getIntent();
        String hora = i.getStringExtra("hora");
        tvHora.setText(hora);

        this.ip = i.getStringExtra("ip");
        this.porta  = i.getIntExtra("porta",12345);

    }

    public void btPegarHora(View view) {
        this.hora = tpHora.getCurrentHour();
        this.minuto = tpHora.getCurrentMinute();

        if(hora <= 9){
            horaFormatada = "0" + hora;
        }else{
            horaFormatada = String.valueOf(hora);
        }

        if(minuto <= 9){
            horaFormatada += ":0" + minuto;
        }else{
            horaFormatada += ":" + String.valueOf(minuto);
        }

        /**
         * Aqui e invocado
         **/
        Thread thread = new Thread(new RunClient(this.ip, this.porta, this, "cf set_hora "+ String.valueOf(hora) + " " + String.valueOf(minuto) + " ;"));
        thread.start();
    }

    /**
     * Caso o servidor confirme que deu certo a hora.
     * Confirma a adiçao da hora.
     **/
    public void setHoraOk(){
        Toast.makeText(this, horaFormatada + " Ok!!", Toast.LENGTH_SHORT).show();
        Intent i = getIntent();
        i.putExtra("hora", horaFormatada);
        setResult(0, i);
        finish();
    }

    /**
     * Caso o servidor diga que nao vai alterar a hora,
     * exibe mensagem de erro.
     **/
    public void setHoraNOk(){

    }
}
