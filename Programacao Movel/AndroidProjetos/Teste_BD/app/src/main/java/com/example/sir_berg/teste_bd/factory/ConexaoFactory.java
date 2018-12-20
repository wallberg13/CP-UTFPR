package com.example.sir_berg.teste_bd.factory;

import android.app.Activity;
import android.content.Context;
import android.database.sqlite.SQLiteDatabase;

public class ConexaoFactory {

    public static SQLiteDatabase bd;

    public static SQLiteDatabase getConnection( Activity context ){

        if(bd == null) {
            bd = context.openOrCreateDatabase("banco", Context.MODE_PRIVATE, null);
            bd.execSQL("CREATE TABLE IF NOT EXISTS cadastro( _id INTEGER PRIMARY KEY AUTOINCREMENT, NOME TEXT, TELEFONE TEXT)");
        }

        return bd;
    }
}
