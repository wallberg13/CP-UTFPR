package prova01.br.com.prova20181;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import prova01.br.com.prova20181.DAO.DisciplinaDAO;
import prova01.br.com.prova20181.Entidade.Disciplina;

public class DisciplinaActivity extends AppCompatActivity {

    private DisciplinaDAO disciplinaDAO;
    private EditText etDisciplina;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_disciplina);

        etDisciplina = (EditText) findViewById( R.id.etDisciplinia );
        disciplinaDAO = new DisciplinaDAO(this);
    }

    public void onClickIncluirDisciplina(View view) {

        Disciplina disc = new Disciplina();
        disc.setNome(etDisciplina.getText().toString());

        disciplinaDAO.incluir(disc);

        Toast.makeText(this, "Disciplina incluida com sucesso!!", Toast.LENGTH_SHORT).show();
    }
}
