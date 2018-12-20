package com.example.administrador.curioso;

import android.content.Context;
import android.database.Cursor;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

/**
 * Created by Administrador on 26/11/2018.
 */

public class MeuAdapter extends BaseAdapter {

    private Context context;
    private Cursor registros;

    public MeuAdapter( Context context, Cursor registros ){

        this.context = context;
        this.registros = registros;

    }

    /**
     *  GetCount - Saber quantos elementos existe na lista.
     **/
    @Override
    public int getCount() {
        return registros.getCount();
    }

    /**
     * Movendo o cursor para uma posicao.
     **/
    @Override
    public Object getItem(int i) {
        registros.moveToPosition(i);
        return registros;
    }

    /**
     * Pegando um item pelo o id
     **/
    @Override
    public long getItemId(int i) {
        return i;
    }

    /**
     *  Logica para desenhar na tela.
     **/
    @Override
    public View getView(int i, View view, ViewGroup viewGroup) {

        LayoutInflater inflater = (LayoutInflater) context.getSystemService(context.LAYOUT_INFLATER_SERVICE);

        View v = inflater.inflate(R.layout.elemento_lista, null);

        TextView tvDescricao = v.findViewById(R.id.tveDescricao);
        TextView tvValor = v.findViewById(R.id.tveValor);
        ImageView ivTipo = v.findViewById(R.id.ivTipo);

        registros.moveToPosition(i);

        tvDescricao.setText(registros.getString(registros.getColumnIndex("descricao")));

        tvValor.setText(String.valueOf(registros.getDouble(registros.getColumnIndex("valor"))));

        String tipo = registros.getString(registros.getColumnIndex("tipo"));

        if (tipo.equalsIgnoreCase("credito")){
            ivTipo.setImageResource(android.R.drawable.btn_plus);
        }else{
            ivTipo.setImageResource(android.R.drawable.btn_minus);
        }

        return v;
    }
}
