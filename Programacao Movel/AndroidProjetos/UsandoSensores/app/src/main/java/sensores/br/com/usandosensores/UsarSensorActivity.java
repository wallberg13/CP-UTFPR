package sensores.br.com.usandosensores;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import java.util.Formatter;

public class UsarSensorActivity extends AppCompatActivity implements SensorEventListener {

    private TextView tvX;
    private TextView tvY;
    private TextView tvZ;

    private SensorManager sm;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_usar_sensor);

        tvX = (TextView) findViewById(R.id.tvX);
        tvY = (TextView) findViewById(R.id.tvY);
        tvZ = (TextView) findViewById(R.id.tvZ);

        /**
         *
         **/
        sm = (SensorManager) getSystemService( SENSOR_SERVICE );

        /**
         * Pegando um objeto do sensor de aceleração.
         **/
        //Sensor sensor = sm.getDefaultSensor( Sensor.TYPE_ACCELEROMETER );
        Sensor sensor = sm.getDefaultSensor( Sensor.TYPE_LIGHT );
        /**
         * Interrupções por Software.
         **/
        sm.registerListener( this, sensor, SensorManager.SENSOR_DELAY_GAME);
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        double x = event.values[0];
      //  double y = event.values[1];
       // double z = event.values[2];

        tvX.setText(String.valueOf(x));
        //tvY.setText(String.valueOf(y));
       // tvZ.setText(String.valueOf(z));
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {

    }
}
