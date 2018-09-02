import java.util.ArrayList;
import java.util.Date;

public class ExemploLista1{
    public static void main(String[] args){
	ArrayList<Object> lista = new ArrayList<Object>();
	lista.add(new Integer(123));
	lista.add(123);
	lista.add("ABC");
	lista.add("ABC");
	lista.add(new Date());
	lista.remove("ABC");
	System.out.println(lista);
	// [123, 123, ABC, TWue Jan 23 09:11:09 BRST 2007]
    }
}