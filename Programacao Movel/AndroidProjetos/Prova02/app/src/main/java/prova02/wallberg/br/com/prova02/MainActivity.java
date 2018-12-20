package prova02.wallberg.br.com.prova02;

import android.content.DialogInterface;
import android.content.Intent;
import android.support.constraint.ConstraintLayout;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import java.text.DecimalFormat;

import prova02.wallberg.br.com.prova02.DAO.FluxoCaixaDAO;

public class MainActivity extends AppCompatActivity {

    private FluxoCaixaDAO fluxoDAO;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        fluxoDAO = new FluxoCaixaDAO(this);
    }

    public void onClickLancar(View view) {
        Intent i = new Intent(this, LancarActivity.class);
        startActivity(i);
    }

    public void onClickTotalPagar(View view) {

        AlertDialog.Builder alerta = new AlertDialog.Builder(this);
        alerta.setTitle("Total Pagar");
        alerta.setCancelable(false);

        DecimalFormat decimalFormat = new DecimalFormat("#.##");
        alerta.setMessage(String.valueOf(decimalFormat.format(fluxoDAO.calculaTotal("Debito"))));

        alerta.setNeutralButton("OK", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {

            }
        });

        alerta.show();
    }

    public void onClickTotalReceber(View view) {

        AlertDialog.Builder alerta = new AlertDialog.Builder(this);
        alerta.setTitle("Total Receber");
        alerta.setCancelable(false);


        DecimalFormat decimalFormat = new DecimalFormat("#.##");
        alerta.setMessage(String.valueOf(decimalFormat.format(fluxoDAO.calculaTotal("Credito"))));

        alerta.setNeutralButton("OK", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {

            }
        });

        alerta.show();
    }
}
