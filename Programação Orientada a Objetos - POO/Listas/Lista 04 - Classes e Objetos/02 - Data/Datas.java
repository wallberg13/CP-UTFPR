public class Datas{
  
  private int dia;
  private int mes;
  private int ano;

  public Datas(){
    dia = 26;
    mes = 07;
    ano = 1995;
  }
  
  public Datas(int dia,int mes,int ano){
    if(dia >= 1 && dia <= 31)
      this.dia = dia;
    else
      this.dia = 26;
    
    if(mes >= 1 && mes <= 12)
      this.mes = mes;
    else
      this.mes = 07;
    
    this.ano = ano;
  }
  
  private String dia_string(int dia){
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
  
  private String mes_string(int mes){
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
  
  public void ImprimeExtenso(){
    if(ano>=0)
      System.out.println(dia_string(dia)+" de "+ mes_string(mes) + " de " + ano + " d.c");
    else
      System.out.println(dia_string(dia)+" de "+ mes_string(mes) + " de " + ((-1)*ano) + " a.c");
  }
  
  public void ImprimeData(){
    System.out.println(dia + "/" + mes + "/" + ano);
  }
  
  /* Sets */
  public void set_dia(int dia){
    if(dia>= 1 && dia <= 31)
      this.dia = dia;
  }
  
  public void set_mes(int mes){
    if(mes>=1 && mes <= 12)
      this.mes = mes;
  
  }
  
  public void set_ano(int ano){
    this.ano = ano;
  }
  
}