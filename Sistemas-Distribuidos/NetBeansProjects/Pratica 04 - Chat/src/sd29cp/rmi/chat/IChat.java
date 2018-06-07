package sd29cp.rmi.chat;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.ArrayList;

public interface IChat extends Remote {
    public ArrayList<Usuario> login(String nome, ICallback callback)
            throws RemoteException;
    public void logout(String nome) throws RemoteException;
    public void broadcastMsg(String de, String msg) throws RemoteException;
}
 