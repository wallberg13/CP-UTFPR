/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio03;

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
    
    public Object trata_requisicao(IDNS dns){
        Object ret = null;
        System.out.println("Requisição recebida " + req + "\n\tOrigem da Requisicao: " + origem);
        String[] aux = req.split(" ");
        
        switch(aux[0]){
            case("bind"):
                try{
                    ret = dns.bind(aux[1], aux[2], Integer.parseInt(aux[3]));
                } catch(DominioJaRegistrado ex){
                    ret = "dominioJaRegistradoExc";
                }
                break;
            
            case("lookup"):
                try{
                    ret = dns.lookup(aux[1]);
                } catch(DominioNaoRegistrado ex){
                    ret = "dominioNaoRegistradoExc";
                }
                break;
            
            case("unbind"):
                try{
                    ret = dns.unbind(aux[1]);
                } catch(DominioNaoRegistrado ex){
                    ret = "dominioNaoRegistradoExc";
                }
                break;
            
            case("list"):
                ret = dns.list();
                break;
            
            default:
                System.out.println("Funcao desconhecida");
                ret = "FuncNaoReconhecida";
                break;
        }
        
        return ret;
    }

}
