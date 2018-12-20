package com.example.sir_berg.ciclodevida;

import android.app.Activity;
import android.os.Bundle;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        System.out.println( "onCreate() executado" );
    }

    @Override
    protected void onStart() {
        super.onStart();
        System.out.println( "onStart() executado" );
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        System.out.println( "onRestart() executado" );
    }

    @Override
    protected void onResume() {
        super.onResume();
        System.out.println( "onResume() executado" );
    }

    @Override
    protected void onPause() {
        super.onPause();
        System.out.println( "onPause() executado" );
    }

    @Override
    protected void onStop() {
        super.onStop();
        System.out.println( "onStop() executado" );
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        System.out.println( "onDestroy() executado" );
    }
}
