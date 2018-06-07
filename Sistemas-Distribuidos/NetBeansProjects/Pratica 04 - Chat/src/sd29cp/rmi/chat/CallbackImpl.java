package sd29cp.rmi.chat;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class CallbackImpl extends UnicastRemoteObject implements ICallback {

    ClienteChatProfessor tela;

    public CallbackImpl(ClienteChatProfessor tela) throws RemoteException {
        super();
        this.tela = tela;
        
    }

    @Override
    public void informarEntradaUsuario(String nome, ICallback callback) throws RemoteException {
        tela.getTxtChat().append("Usuario " + nome + " entrou no Chat\n");
        tela.getAmigosConectados().addElement(new Usuario(nome, callback));
    }

    @Override
    public void informarSaidaUsuario(String nome) throws RemoteException {
        tela.getTxtChat().append("Usuario " + nome + " saiu do chat!\n");
        
        int j = tela.getAmigosConectados().size();
        Usuario remover = null;
        Usuario aux;
        for(int i = 0; i < j; i++){
            aux = (Usuario) tela.getAmigosConectados().get(i);
            if(aux.getNome().equals(nome)){
                remover = aux;
                break;
            }
        }
        tela.getAmigosConectados().removeElement(remover);
    }

    @Override
    public void enviarMsg(String de, String msg) throws RemoteException {
        tela.getTxtChat().append(de + " escreveu: " + msg + "\n");
    }
}
