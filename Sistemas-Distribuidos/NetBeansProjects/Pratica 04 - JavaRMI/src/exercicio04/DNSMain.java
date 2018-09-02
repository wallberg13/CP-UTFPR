/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio04;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

/**
 *
 * @author sir-berg
 */
public class DNSMain {
    
    private IDNS dns;
    
    public DNSMain(String ip, int porta) {
        try{
            Registry registro = LocateRegistry.getRegistry(ip, porta);
            dns = (IDNS) registro.lookup("DNS");
        } catch (NotBoundException ex){
            System.out.println("Objeto nao encontrado: " + ex.getMessage());
        } catch (RemoteException ex) {
            System.out.println("buce: " + ex.getMessage());
        }
        iniciar();
    }
    
    public void iniciar(){
        try{

            dns.bind("w@ll","123456", 9090);

            dns.bind("w@ll23","12323456", 9090);
            dns.bind("w@23","123234560", 9090);

            imprimeVetString(dns.list());

            System.out.println("IP do Dominio w@ll: " + dns.lookup("w@ll"));

            imprimeVetString(dns.list());

            dns.unbind("w@ll23");

            imprimeVetString(dns.list());
        } catch (RemoteException ex){
            System.out.println("Buce: " + ex.getMessage());            
        }

    }
    
    public static void main(String[] args){
        DNSMain apl = new DNSMain("127.0.0.1", 4321);
    }
    
    public void imprimeVetString(String[] vet){
        System.out.println("Dominios Registrados: ");
        for(String str: vet){
            System.out.println(str);
        }
    }
}
