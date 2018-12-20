package prova02.wallberg.br.com.prova02;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

import prova02.wallberg.br.com.prova02.DAO.DescricoesDAO;
import prova02.wallberg.br.com.prova02.DAO.FluxoCaixaDAO;
import prova02.wallberg.br.com.prova02.Entidade.Descricoes;
import prova02.wallberg.br.com.prova02.Entidade.FluxoCaixa;

public class LancarActivity extends AppCompatActivity {

    private FluxoCaixaDAO fluxoDAO;
    private DescricoesDAO descriDAO;
    private Spinner spTipo;
    private AutoCompleteTextView actvDescricao;
    private EditText etValor;

    final String tipo[] = {"Debito", "Credito"};

    private String tipo_sel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lancar);

        fluxoDAO = new FluxoCaixaDAO(this);
        descriDAO = new DescricoesDAO(this);

        spTipo = (Spinner) findViewById(R.id.spTipo);
        actvDescricao = (AutoCompleteTextView) findViewById(R.id.actvDescricao);
        etValor = (EditText) findViewById(R.id.etValor);

        actvDescricao.setThreshold(1);

        ArrayAdapter adapterSpinner = new ArrayAdapter(this, android.R.layout.simple_list_item_1, tipo);
        spTipo.setAdapter(adapterSpinner);

        spTipo.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                tipo_sel = tipo[position];
                String descValues[] = descriDAO.listarDescricao(tipo_sel);

                if(descValues != null) {
                    ArrayAdapter adapterACTV = new ArrayAdapter(LancarActivity.this, android.R.layout.simple_list_item_1, descValues);
                    actvDescricao.setAdapter(adapterACTV);
                }else{
                    actvDescricao.setAdapter(null);
                }
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });

    }

    public void onClickInserirLancamento(View view) {

        if(actvDescricao.getText().toString().equals("")){
            actvDescricao.setError("Preencha este campo");
            return;
        }

        if(etValor.getText().toString().equals("")){
            etValor.setError("Preecha este campo");
            return;
        }


        /**
         * Fazendo inclusao do Fluxo de Caixa
         **/
        FluxoCaixa fc = new FluxoCaixa();
        fc.setDescricao(actvDescricao.getText().toString());
        fc.setTipo(tipo_sel);
        fc.setValor(Double.valueOf(etValor.getText().toString()));
        fluxoDAO.incluir(fc);

        /**
         * Fazendo inclusao na tabela descricao.
         * Caso for adicionado uma descricao que já existe no banco, irá dá um erro, porém,
         * este erro não é interpretado.
         **/
        Descricoes dc = new Descricoes();
        dc.setDescricao(fc.getDescricao());
        dc.setTipo(tipo_sel);
        descriDAO.incluir(dc);

        Toast.makeText(this, "Lancamento Incluido com Sucesso!!", Toast.LENGTH_SHORT).show();

        // Limpando Campos
        actvDescricao.setText("");
        etValor.setText("");
        actvDescricao.requestFocus();
    }

    public void onClickVoltar(View view) {
        finish();
    }
}
