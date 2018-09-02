public class Main{
  
  public static void main(String[] args){
    Datas d1 = new Datas();
    Datas d2 = new Datas(20,8,-2015);
    
    d1.ImprimeExtenso();
    d1.ImprimeData();
    
    d2.ImprimeExtenso();
    d2.ImprimeData();
    
    d1.set_dia(21);
    d1.set_mes(12);
    d1.set_ano(2015);
    d1.ImprimeExtenso();
    d1.ImprimeData();
  }
  
}