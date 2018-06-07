/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio04;

/**
 *
 * @author sir-berg
 */
public class DNSMain {
    
    DNSImple dns = null;
    
    public DNSMain() throws DominioJaRegistrado, DominioNaoRegistrado {
        dns = new DNSImple();
        iniciar();
    }
    
    public void iniciar() throws DominioJaRegistrado, DominioNaoRegistrado{
        try{
            dns.bind("w@ll","123456", 9090);  
            dns.bind("w@ll","123456", 9090); // Aqui ele dá o exception
        }catch(DominioJaRegistrado e){
            System.out.println(e.getMessage());
        }
        
        dns.bind("w@ll23","12323456", 9090);
        dns.bind("w@23","123234560", 9090);
        
        imprimeVetString(dns.list());
        
        try{
            dns.lookup("xiter");
        }catch(DominioNaoRegistrado e){
            System.out.println(e.getMessage());
        }
        
        try{
            System.out.println("IP do Dominio w@ll: " + dns.lookup("w@ll"));
        }catch(DominioNaoRegistrado e){
            System.out.println(e.getMessage());
        }
        
        imprimeVetString(dns.list());
        
        dns.unbind("w@ll23");
        
        imprimeVetString(dns.list());
        
    }
    
    public static void main(String[] args) throws DominioJaRegistrado, DominioNaoRegistrado{
        DNSMain apl = new DNSMain();
    }
    
    public void imprimeVetString(String[] vet){
        System.out.println("Dominios Registrados: ");
        for(String str: vet){
            System.out.println(str);
        }
    }
}
