package sd29cp.rmi.chat;

import java.rmi.*;

public interface ICallback extends Remote {
    public void informarEntradaUsuario(String nome, ICallback callback) throws RemoteException;
    public void informarSaidaUsuario(String nome) throws RemoteException;
    public void enviarMsg(String de, String msg) throws RemoteException;
}
