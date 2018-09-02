/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio02;

/**
 *
 * @author sir-berg
 */
public class Requisicao {
    private String req = null;
    private String origem = null;
    
    public Requisicao(String req, String origem){
        this.req = req.trim();
        this.origem = origem;
    }
    
    /**
     * Método que tem como objetivo retornar uma resposta da requisição que foi dado a ele.
     * Retorna um objeto onde quem está recebendo o mesmo ira tratar. Mas isso só vale para 
     * requisicoes em java.
     * @return 
     */
    public String trata_requisicao(IHoraCerta hc){
        String retorno = null;
        System.out.println("Requisição recebida: " + req + " Origem da Requisicao: " + origem);
        String[] aux = req.split(" ");
                        
        switch(aux[0]){
            case("dataAtual"):
                retorno = hc.dataAtual();
                break;
            case("horaAtual"):
                retorno = hc.horaAtual();
                break;
            default:
                retorno = "Funcao invalida";
        }
        
        return retorno;
    }
    
}
