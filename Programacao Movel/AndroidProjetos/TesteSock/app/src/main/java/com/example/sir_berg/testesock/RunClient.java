package com.example.sir_berg.testesock;

import android.app.Activity;
import android.widget.Toast;

class RunClient implements Runnable{
    private String ip;
    private int porta;
    private Activity context;
    private ClientTCP cli;
    private String requi;

    public RunClient(String ip, int porta, Activity context, String requi){
        this.ip = ip;
        this.porta = porta;
        this.context = context;
        this.requi = requi;
    }

    /**
     * Todas as Activities irao chamar a mesma funcao para enviar.
     *
     * Cada Activity ira possuir um codigo antes da funcao que e preciso enviar pela requisicao.
     * Esse codigo e um "sigla" do nome dela. Como exemplo, MainActivity sera representada por "ma".
     * Entao, as requisicoes que vierem dessa activity devem voltar para aquela activity especifica, para
     * isso, e necessario como parametro de entrada um valor generico para todas as activities e
     * na string de requisicao ser especificado quem fez o que.
     *
     **/
    @Override
    public void run() {

        // Primeiramente, tratando a String de entrada, e removendo o primeiro termo dela.
        String act = null, func = null;

        act = requi.split(" ")[0];
        func = requi.split(" ")[1];

        // Removendo o prefixo do nome da Activity, pois o servidor nao precisa interpretar.
        this.requi = this.requi.replaceFirst(act + " ", "");

        // Criando um objeto ClientTCP, e enviando a requisicao.
        cli = new ClientTCP(this.ip, this.porta, context);
        final String resp = cli.ClientSendReq(this.requi, this.context);

        /**
         * A nao ser que a requisicao tenha sido um status de toda a aplicacao,
         * as demais funcoes e de alteracao de alguma coisa, ou possui um retorno.
         *
         * Com isso, e necessario interpretar esses retornos e analisar se deu boa ou nao.
         **/
        switch (act){
            case "ma": // MainActivity
                final MainActivity auxMA = (MainActivity)context;
                auxMA.runOnUiThread( new Thread() {
                    public void run(){
                        auxMA.setTvLogServer(resp);
                        auxMA.getEtTexto().setText("");
                        auxMA.getEtTexto().requestFocus();
                    }
                });
                break;

            case "cf": // Configuracao.
                final Configuracao auxC = (Configuracao)context;
                auxC.runOnUiThread( new Thread(){
                    public void run(){
                        auxC.setHoraOk();
                        Toast.makeText(auxC, "Alguma coisa veio de Configuracao", Toast.LENGTH_SHORT).show();
                    }
                });
                break;

            default:
                break;
        }


        cli.ClientClose(context);
    }
}