package sd29cp.rmi.chat;

import java.rmi.RemoteException;
import java.rmi.registry.*;


public class Servidor {

    public Servidor() {
        try {
            IChat chat = new ChatImpl();
            Registry registro = LocateRegistry.createRegistry(1099);
            
            //Registry registro = LocateRegistry.getRegistry("127.0.0.1", 1099);
            registro.rebind("MeuChat", chat);
            System.out.println("Servidor Chat executando...");
        } catch (RemoteException ex) {
            System.err.println("Erro: " + ex.getMessage());
        }

    }

    public static void main(String[] args) {
        Servidor s = new Servidor();
    }   

}
