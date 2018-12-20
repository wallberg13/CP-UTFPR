package com.example.sir_berg.componentesvisuaisavancados;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.DatePicker;
import android.widget.RadioButton;
import android.widget.Toast;

import java.text.SimpleDateFormat;
import java.util.Date;

public class MainActivity extends AppCompatActivity {

    private RadioButton rbMasc;
    private RadioButton rbFem;

    private CheckBox cbNatacao;
    private CheckBox cbCorrida;
    private CheckBox cbFutebol;

    private DatePicker dpData;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        rbMasc = (RadioButton) findViewById( R.id.rbMasc );
        rbFem = (RadioButton) findViewById( R.id.rbFem );

        cbCorrida = (CheckBox) findViewById( R.id.cbCorrida );
        cbFutebol = (CheckBox) findViewById( R.id.cbFutebol );
        cbNatacao = (CheckBox) findViewById( R.id.cbNatacao );

        dpData = (DatePicker) findViewById( R.id.dpData );
    }

    public void btTestarComponenteOnClick(View view) {

        if(rbMasc.isChecked()){
            Toast.makeText(this, "Sexo Masculino", Toast.LENGTH_SHORT).show();
        }else{
            Toast.makeText(this, "Sexo Feminino", Toast.LENGTH_SHORT).show();
        }

        String text = "";

        if(cbNatacao.isChecked()){
            text += "Nataçao";
        }

        if (cbCorrida.isChecked()){
            if(text.equals(""))
                text += "Corrida";
            else
                text += ", Corrida";
        }

        if (cbFutebol.isChecked()){
            if(text.equals(""))
                text += "Futebol";
            else
                text += ", Futebol";
        }

        Toast.makeText(this, text, Toast.LENGTH_SHORT).show();

        /**
         * DataPicker
         **/
        int dia = dpData.getDayOfMonth();
        int mes = dpData.getMonth();
        int ano = dpData.getYear();

        String dataFormatada = dia + "/" + (mes + 1) + "/" + ano;
        SimpleDateFormat formatador = new SimpleDateFormat( "dd/MM/yyyy");

        try {
            Date info = formatador.parse(dataFormatada);
        }catch (Exception e){
            e.printStackTrace();
        }


    }
}
