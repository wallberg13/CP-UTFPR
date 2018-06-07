/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio02;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 *
 * @author sir-berg
 */
public class IHoraCertaImpl extends UnicastRemoteObject implements IHoraCerta{

    public IHoraCertaImpl() throws RemoteException{
        super();
    }
    @Override
    public String dataAtual() throws RemoteException{
        Date dataAgora = new Date();
        SimpleDateFormat sdf = new SimpleDateFormat("dd/mm/yyyy");
        return sdf.format(dataAgora);
    }

    @Override
    public String horaAtual() throws RemoteException{
        Date horaAgora = new Date();
        SimpleDateFormat sdf = new SimpleDateFormat("hh:mm:ss.SSS");
        return sdf.format(horaAgora);
    }
    
}
