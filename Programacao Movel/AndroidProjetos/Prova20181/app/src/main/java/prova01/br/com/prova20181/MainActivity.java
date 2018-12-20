package prova01.br.com.prova20181;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Adapter;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.SimpleAdapter;

public class MainActivity extends AppCompatActivity {

    private ListView lvOpcoes;
    private String[] opcoes = { "Disciplina", "Nota" };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        lvOpcoes = (ListView) findViewById( R.id.lvOpcoes );

        ArrayAdapter adapter = new ArrayAdapter(this, android.R.layout.simple_list_item_1, opcoes);

        lvOpcoes.setAdapter(adapter);

        lvOpcoes.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                if(position == 0){ // Chama Disciplina
                    callIncludeDisciplina();
                }

                if(position == 1){ // Chama Nota
                    callIncludeNota();
                }
            }
        });
    }

    private void callIncludeDisciplina(){
        Intent i = new Intent(this, DisciplinaActivity.class);
        startActivity(i);
    }

    private void callIncludeNota(){
        Intent i = new Intent(this, NotaActivity.class);
        startActivity(i);
    }
}
