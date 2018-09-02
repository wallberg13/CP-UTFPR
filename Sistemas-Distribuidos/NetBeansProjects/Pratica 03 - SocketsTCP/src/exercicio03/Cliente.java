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
public class Cliente {
    private IDNS dns = null;
    
    public Cliente(String ip, int porta){
        this.dns = new ProxyDNS(ip, porta);
        init();
    }
    
    public void init(){
        try{
            dns.bind("w@ll","123456", 9090);  
            dns.bind("w@ll23","12323456", 9090);
            dns.bind("w@23","123234560", 9090);
            dns.bind("w@ll","123456", 9090); 
        }catch(DominioJaRegistrado e){
            System.out.println(e.getMessage());
        }
        
      
        imprimeVetString(dns.list());
           
        try{
            System.out.println("IP do Dominio w@ll: " + dns.lookup("w@ll"));
        }catch(DominioNaoRegistrado e){
            System.out.println(e.getMessage());
        }
        
        imprimeVetString(dns.list());
        
        try{
            System.out.println("Dando unbind em w@ll23");
            dns.unbind("w@ll23");
        } catch (DominioNaoRegistrado ex){
            System.out.println("Mensagem " + ex.getMessage());
        }
        imprimeVetString(dns.list());
    }
    
    public static void main(String[] args){
        Cliente c = new Cliente("127.0.0.1", 4321);
    }
    
    public void imprimeVetString(String[] vet){
        System.out.println("Dominios Registrados: ");
        for(String str: vet){
            System.out.println(str);
        }
    }
}
