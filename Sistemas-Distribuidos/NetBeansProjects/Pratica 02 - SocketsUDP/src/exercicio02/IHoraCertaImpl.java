/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio02;

import java.text.SimpleDateFormat;
import java.util.Date;

/**
 *
 * @author sir-berg
 */
public class IHoraCertaImpl implements IHoraCerta{

    @Override
    public String dataAtual() {
        Date dataAgora = new Date();
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        return sdf.format(dataAgora);
    }
    
    @Override
    public String horaAtual() {
        Date horaAgora = new Date();
        SimpleDateFormat sdf = new SimpleDateFormat("hh:mm:ss.SSS");
        return sdf.format(horaAgora);
    }
    
}
