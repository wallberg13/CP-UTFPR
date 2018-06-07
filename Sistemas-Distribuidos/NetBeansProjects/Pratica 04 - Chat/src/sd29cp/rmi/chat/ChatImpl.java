/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sd29cp.rmi.chat;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;

/**
 *
 * @author favarim
 */
public class ChatImpl extends UnicastRemoteObject implements IChat  {

    ArrayList <Usuario> usuariosConectados;

    public ChatImpl() throws RemoteException {
        super();
        usuariosConectados = new ArrayList<Usuario>();
    }
    
    /** 
     *  Quem chama o ChatImpl é o usuario que esta entrando.
     *  Entao ele entra no chat, informa quem é ele, o servidor avisa quem esta entrando
     *  para todos conectados e tbm adiciona o proprio usuario na lista.
     * @param nome
     * @param callback
     * @return 
     * @throws java.rmi.RemoteException
     */
    @Override
    public ArrayList<Usuario> login(String nome, ICallback callback) throws RemoteException {
        
        for(Usuario usr: usuariosConectados){
            usr.getCallback().informarEntradaUsuario(nome, callback);
        }
        
        usuariosConectados.add(new Usuario(nome, callback));
        System.out.println("Usuario: " + nome + " se conectou");
        return usuariosConectados;
    }

    /** 
     * Fazendo o logout. Todos os usuarios sao informados que estou saindo.
     */
    @Override
    public void logout(String nome) throws RemoteException {
        Usuario usuarioRemover = null;
        
        for(Usuario usr: usuariosConectados){
            if(usr.getNome().equals(nome)){
                usuarioRemover = usr;
            }else{
                usr.getCallback().informarSaidaUsuario(nome);
            }
        }
        usuariosConectados.remove(usuarioRemover);
        System.out.println("Usuario: " + nome + " se desconectou!!");
    }

    @Override
    public void broadcastMsg(String de, String msg) throws RemoteException {
        for(Usuario u: usuariosConectados){
            if(!u.getNome().equals(de)){
                u.getCallback().enviarMsg(de, msg);
            }
        }
    }
    
    
}
