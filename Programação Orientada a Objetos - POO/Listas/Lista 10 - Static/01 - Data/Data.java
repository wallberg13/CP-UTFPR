import java.lang.Math;

public class Data{

    private static String dia_string(int dia){
	switch(dia){
	case 1:
	    return "Primeiro";
	case 2:
	    return "Dois";
	case 3:
	    return "Três";
	case 4:
	    return "Quatro";
	case 5:
	    return "Cinco";
	case 6:
	    return "Seis";
	case 7:
	    return "Sete";
	case 8:
	    return "Oito";
	case 9:
	    return "Nove";
	case 10:
	    return "Dez";
	case 11:
	    return "Onze";
	case 12:
	    return "Doze";
	case 13:
	    return "Treze";
	case 14:
	    return "Catorze";
	case 15:
	    return "Quinze";
	case 16:
	    return "Dezesseis";
	case 17:
	    return "Dezessete";
	case 18:
	    return "Dezoito";
	case 19:
	    return "Dezenove";
	case 20:
	    return "Vinte";
	case 21:
	    return "Vinte e um";
	case 22:
	    return "Vinte e dois";
	case 23:
	    return "Vinte e três";
	case 24:
	    return "Vinte e quatro";
	case 25:
	    return "Vinte e cinzo";
	case 26:
	    return "Vinte e seis";
	case 27:
	    return "Vinte e sete";
	case 28:
	    return "Vinte e oito";
	case 29:
	    return "Vinte e nove";
	case 30:
	    return "Trinta";
	case 31:
	    return "Trinta e um";
	}
	//Retorna um dia qualquer.
	return "Vinte e seis";
    }

    private static String mes_string(int mes){
	switch(mes){
	case 1:
	    return "janeiro";
	case 2:
	    return "fevereiro";
	case 3:
	    return "março";
	case 4:
	    return "abril";
	case 5:
	    return "maio";
	case 6:
	    return "junho";
	case 7:
	    return "julho";
	case 8:
	    return "agosto";
	case 9:
	    return "setembro";
	case 10:
	    return "outubro";
	case 11:
	    return "novembro";
	case 12:
	    return "dezembro";
	}
	//Retorna um mes qualquer.
	return "julho";
    }

    public static void imprimirExtenso(int d,int m,int a){
	if(validaEntrada(d,m,a) == false){
	    System.out.println("Data invalida");
	    return;
	}
	if(a>=0)
	    System.out.println(dia_string(d)+" de "+ mes_string(m) + " de " + a + " d.c");
	else
	    System.out.println(dia_string(d)+" de "+ mes_string(m) + " de " + ((-1)*a) + " a.c");
    }
    
    public static void imprimirExtenso(int d,int m){
	if(validaEntrada(d,m) == false){
	    System.out.println("Dia e mês invalidos");
	    return;
	}
    	System.out.println(dia_string(d)+" de "+ mes_string(m));
    }

    public static void imprimirExtenso(int d){
	if(validaEntrada(d) == false){
	    System.out.println("Dia do mês invalido.");
	}
	    System.out.println(dia_string(d));
    }

    public static void imprimirMes(int m){
	if(m>0 && m<=12)
	    System.out.println(mes_string(m));
	else
	    System.out.println("Mês invalido.");
    }
    
    public static boolean validaEntrada(int dia, int mes, int ano){
	int max = 0; //Maximo de dia em cada mês
	
	if(mes <= 0 || mes > 12)
	    return false;
	
	if(ano%4 == 0 && ano%100 != 0){
	    if(mes == 2)
		max = 29; //Fevereiro
	}else{
	    if(mes == 2)
		max = 28;
		
	    if(mes <= 7 && mes%2 == 0 && mes != 2)
		max = 30;
	    else{
		if(mes <= 7 && mes%2 == 1)
		    max = 31;
	    }
	    if(mes > 7 && mes%2 == 0)
		max = 31;
	    else{
		if(mes > 7 && mes%2 == 1)
		    max = 30;
	    }
	}
	if(dia<=0 || dia>max)
	    return false;
	    
	return true;
    }
    
    public static boolean validaEntrada(int dia, int mes){
	int max = 0; //Maximo de dia em cada mês
	
	if(mes <= 0 || mes > 12)
	    return false;
	
	
	if(mes == 2)
	    max = 28;
	    
	if(mes <= 7 && mes%2 == 0 && mes != 2)
	    max = 30;
	else{
	    if(mes <= 7 && mes%2 == 1)
		max = 31;
	}
	
	if(mes > 7 && mes%2 == 0)
	    max = 31;
	else{
	    if(mes > 7 && mes%2 == 1)
		max = 30;
	}
	    
	if(dia<=0 || dia>max)
	    return false;
	    
	return true;
    }
    
    public static boolean validaEntrada(int dia){
	if(dia <= 0 || dia > 31)
	    return false;
	else
	    return true;
    }
    
    public static void Diferenca(int d1,int m1,int a1,int d2,int m2,int a2){
	if(validaEntrada(d1,m1) == false || validaEntrada(d2,m2) == false){
	    System.out.println("Uma(ambas) data(s) está invalida.");
	    return;
	}

	long datadias1,datadias2;
	datadias1 = a1*365 + m1*30 + d1;
	datadias2 = a2*365 + m2*30 + d2;
	
	System.out.println("A diferença é: "+Math.abs(datadias1 - datadias2)+" dia(s)");
    }
    
    
}