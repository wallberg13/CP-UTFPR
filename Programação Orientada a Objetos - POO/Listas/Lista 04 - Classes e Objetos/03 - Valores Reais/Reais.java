public class Reais{
  private int m; //Milhar
  private int c; //Centena
  private int d; //Dezena
  private int u; //Unidade
  private int d1; //Decimal 01
  private int d2; //Decimal 02
  
  public Reais(){
    m = 0;
    c = 1;
    d = 1;
    u = 0;
    d1 = 0;
    d2 = 0;
  }
   
  public Reais(Double din){
    if(din <= 1000.00 && din >= -1000.00){
      m = (int)(din/1000);
      c = (int)(din/100) - m*10;
      d = (int)(din/10) - m*100 - c*10;
      u = (int)(din - m*1000 - c*100 - d*10);
      d1 = (int)(din*10 - m*10000 - c*1000 - d*100 - u*10); 
      d2 = (int)(din*100 - m*100000 - c*10000 - d*1000 - u*100 - d1*10); 
    }else{
      m = 0;
      c = 1;
      d = 1;
      u = 0;
      d1 = 0;
      d2 = 0;
    }
  }
  
  public void imprimeExtenso(){
    if(m == 1)
      System.out.println("Mil" + centena() + "" + dezena() + "" + unidade() + " Reais ");
    if(d1 != 0 || d2 != 0)
      System.out.println(centena() + " " + dezena() + "" + unidade() + "Reais e " + dezena(d1) + "" + unidade(d2) + "centavos ");
    else
      System.out.println(centena() + " " + dezena() + "" + unidade() + "Reais ");
  }
  
  private String centena(){
    switch(c){
      case 1: 
	if(d != 0 || u != 0)
	  return "Cem e";
	else
	  return "Cem";
      case 2: 
	if(d != 0 || u != 0)
	  return "Duzentos e";
	else
	  return "Duzentos";
      case 3:
	if(d != 0 || u != 0)
	  return "Trezentos e";
	else
	  return "Trezentos";
      case 4: 
        if(d != 0 || u != 0)
	  return "Quatrocentos e";
	else
	  return "Quatrocentos";
      case 5: 
        if(d != 0 || u != 0)
          return "Quinhentos e";
        else
	  return "Quinhentos";
      case 6: 
	if(d != 0 || u != 0)
	  return "Seiscentos e";
	else
	  return "Seiscentos";
      case 7: 
	if(d != 0 || u != 0)
	  return "Setecentos e";
	else
	  return "Setecentos";
      case 8: 
	if(d != 0 || u != 0)
	  return "Oitocentos e";
	else
	  return "Oitocentos";
      case 9: 
	if(d != 0 || u != 0)
	  return "Novecentos e";
	else
	  return "Novecentos";
    }
    return "";
  }
  
  private String dezena(){
    if(d*10 + u > 20){
	switch(d){
	case 2: 
	    if( u != 0)
		return "Vinte e ";
	    else
		return "Vinte ";
	case 3: 
	    if( u != 0)
		return "Trinta e ";
	    else
		return "Trinta ";
	case 4: 
	    if( u != 0)
		return "Quarenta e ";
	    else
		return "Quarenta ";
	case 5: 
	    if( u != 0)
		return "Cinquenta e ";
	    else
		return "Cinquenta ";
	case 6: 
	    if( u != 0)
		return "Sessenta e ";
	    else
		return "Sessenta ";
	case 7: 
	    if( u != 0)
		return "Setenta e ";
	    else
		return "Setenta ";
	case 8: 
	    if( u != 0)
		return "Oitenta e ";
	    else
		return "Oitenta ";
	case 9: 
	    if( u != 0)
		return "Noventa e ";
	    else
		return "Noventa ";
	}
    }else{
	switch(10*d + u){
	    case 11:
		return "Onze ";
	    case 12:
		return "Doze ";
	    case 13:
		return "Treze ";
	    case 14:
		return "Quatoze ";
	    case 15:
		return "Quinze ";
	    case 16:
		return "Dezeseis ";
	    case 17:
		return "Dezesete ";
	    case 18:
		return "Dezoito ";
	    case 19:
		return "Dezenove ";
	}
    }
    return "";
  }
  
  private String unidade(){
    if(d != 1){
	switch(u){
	    case 1: return "Um ";
	    case 2: return "Dois ";
	    case 3: return "Três ";
	    case 4: return "Quatro ";
	    case 5: return "Cinco ";
	    case 6: return "Seis ";
	    case 7: return "Sete ";
	    case 8: return "Oito ";
	    case 9: return "Nove ";
	}
    }
    return "";
  }
  
  private String dezena(int d1){
    if(d1*10 + d2 > 20){
	switch(d1){
	case 2: 
	    if( u != 0)
		return "Vinte e ";
	    else
		return "Vinte ";
	case 3: 
	    if( u != 0)
		return "Trinta e ";
	    else
		return "Trinta ";
	case 4: 
	    if( u != 0)
		return "Quarenta e ";
	    else
		return "Quarenta ";
	case 5: 
	    if( u != 0)
		return "Cinquenta e ";
	    else
		return "Cinquenta ";
	case 6: 
	    if( u != 0)
		return "Sessenta e ";
	    else
		return "Sessenta ";
	case 7: 
	    if( u != 0)
		return "Setenta e ";
	    else
		return "Setenta ";
	case 8: 
	    if( u != 0)
		return "Oitenta e ";
	    else
		return "Oitenta ";
	case 9: 
	    if( u != 0)
		return "Noventa e ";
	    else
		return "Noventa ";
	}
    }else{
	switch(10*d1 + d2){
	    case 11:
		return "Onze ";
	    case 12:
		return "Doze ";
	    case 13:
		return "Treze ";
	    case 14:
		return "Quatoze ";
	    case 15:
		return "Quinze ";
	    case 16:
		return "Dezeseis ";
	    case 17:
		return "Dezesete ";
	    case 18:
		return "Dezoito ";
	    case 19:
		return "Dezenove ";
	}
    }
    return "";
  }
  
  private String unidade(int d2){
    switch(d2){
      case 1: return "Um ";
      case 2: return "Dois ";
      case 3: return "Três ";
      case 4: return "Quatro ";
      case 5: return "Cinco ";
      case 6: return "Seis ";
      case 7: return "Sete ";
      case 8: return "Oito ";
      case 9: return "Nove ";
    }
    return "";
  }
  
  public void imprime(){
    if(m==1)
	System.out.println("R$ "+m+c+d+u+","+d1+d2);
    else
	System.out.println("R$ "+c+d+u+","+d1+d2);
  
  }
}