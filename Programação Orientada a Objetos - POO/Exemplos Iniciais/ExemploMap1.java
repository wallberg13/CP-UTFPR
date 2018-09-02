import java.util.HashMap;

public class ExemploMap1{

    public static void main(String[] args){

	HashMap<Object, Object> mapa = new HashMap<Object, Object>();
	mapa.put(1, "um");
	mapa.put(2, "dois");
	mapa.put(3, "quatro");
	mapa.put(3, "três");
	mapa.remove("dois"); // ?
	mapa.remove(2); // ok
	mapa.put(0.0, "zero");
	mapa.put(0, "zero");
	System.out.println(mapa);
	// {1=um, 3=três, 0=zero, 0.0=zero}

    }

}