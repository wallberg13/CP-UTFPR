package com.example.sir_berg.teste_bd;

import android.content.DialogInterface;
import android.content.Intent;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;
import com.example.sir_berg.teste_bd.dao.CadastroDAO;
import com.example.sir_berg.teste_bd.entidade.Cadastro;


public class MainActivity extends AppCompatActivity {

    private EditText etCod;
    private EditText etNome;
    private EditText etTelefone;

    private DatabaseHandle cadDao;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        etCod = (EditText) findViewById( R.id.etCod );
        etNome = (EditText) findViewById( R.id.etNome );
        etTelefone = (EditText) findViewById( R.id.etTelefone );

        //cadDao = new CadastroDAO( this );
        cadDao = new DatabaseHandle( this );
    }

    public void btIncluirOnClick(View view) {

        Cadastro cad = new Cadastro();

        cad.setNome( etNome.getText().toString() );
        cad.setTelefone( etTelefone.getText().toString() );

        cadDao.incluir(cad);

        Toast.makeText(this, "Dado Incluido", Toast.LENGTH_SHORT).show();

        etNome.setText("");
        etTelefone.setText("");

    }

    public void btAlterarOnClick(View view) {

        Cadastro cad = new Cadastro();
        cad.setCod( Integer.parseInt( etCod.getText().toString()));
        cad.setNome( etNome.getText().toString());
        cad.setTelefone(etTelefone.getText().toString());

        cadDao.alterar( cad );

        Toast.makeText(this, "Registro alterado com sucesso!", Toast.LENGTH_LONG).show();
    }

    public void btExcluirOnClick(View view) {
        String cod = etCod.getText().toString();

        cadDao.excluir( Integer.parseInt(cod) );

        Toast.makeText(this, "Exclusão Efetuada com Sucesso", Toast.LENGTH_LONG).show();
    }

    public void btPesquisarOnClick(View view) {

        final EditText etCodAlerta = new EditText( this ); // Criando um EditText dinamicamente

        AlertDialog.Builder alerta = new AlertDialog.Builder( this );
        alerta.setTitle( " Favor Digitar o código" );
        alerta.setCancelable( false );
        alerta.setNeutralButton("OK", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {

                String cod = etCodAlerta.getText().toString();
                Cadastro cad = cadDao.pesquisar(Integer.parseInt(cod));

                if(cad != null){
                    Toast.makeText(MainActivity.this, "Nome: " + cad.getNome() + " - " + cad.getTelefone(), Toast.LENGTH_SHORT).show();
                }else{
                    Toast.makeText(MainActivity.this, "Registro não encontrado!!", Toast.LENGTH_SHORT).show();
                }

            }
        });

        alerta.setView( etCodAlerta );
        alerta.show();
    }

    public void btListarOnClick(View view) {
//        Cursor registros = bd.query("cadastro", new String[] {"NOME", "TELEFONE"}, null, null, null, null, null);

  //      String resposta = "";

    //    while( registros.moveToNext() ){
        //    resposta += registros.getString( registros.getColumnIndex( "NOME" )) + " - " + registros.getString( registros.getColumnIndex( "TELEFONE") ) + "\n";
      //  }

        Intent i = new Intent(this, ListaCampos.class);
        startActivity(i);
        //Toast.makeText(this, resposta, Toast.LENGTH_SHORT).show();

    }

    /**
     * Esqueceu do aplicativo e esqueceu de algo e esqueceu no banco de dados de criar a coluna
     * Lembrar de não dá merda no banco.
     **/
}
