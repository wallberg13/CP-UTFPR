package sensores.br.com.usandosensores;

import android.content.Intent;
import android.hardware.Sensor;
import android.hardware.SensorManager;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.Iterator;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private SensorManager sm;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        sm = (SensorManager) getSystemService( SENSOR_SERVICE );

    }

    public void btListarOnClick(View view) {

        ListView lista = new ListView(this);

        String sensores[] = montaListaSensores();
        ArrayAdapter adapter = new ArrayAdapter(this, android.R.layout.simple_list_item_1, sensores);
        lista.setAdapter(adapter);

        AlertDialog.Builder alerta = new AlertDialog.Builder(this);

        alerta.setView( lista );
        alerta.setCancelable( false );
        alerta.setNeutralButton( "Ok", null);

        alerta.show();
    }

    private String[] montaListaSensores() {
        String ret[] = null;
        List<Sensor> sensores = sm.getSensorList(Sensor.TYPE_ALL);
        ret = new String[sensores.size()];

        Iterator<Sensor> iterator = sensores.iterator();

        int i = 0;

        while ( iterator.hasNext() ){
            Sensor sensor = iterator.next();
            ret[i] = sensor.getName();
            i++;
        }

        return ret;
    }

    public void btSensorOnClick(View view) {
        Intent i = new Intent(this, UsarSensorActivity.class);
        startActivity(i);
    }
}
