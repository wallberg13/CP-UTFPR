public class Main{

    public static void main(String[] args){
	IntergerSet s1 = new IntergerSet(13);
	IntergerSet s2 = new IntergerSet(14);
	IntergerSet s3 = new IntergerSet();
	
	//Imprimindo a união entre s1 e s2 no s3
	s3.union(s1,s2);
	s3.toSetString();
	
	//Delentando todos os elementos de s3 para mostrar a forma
	//vazia dele.
	s3.deleteElement(13);
	s3.deleteElement(14);
	s3.toSetString();
	
	//Testando a isEqualTo (Condição verdadeira)
	s1.insertElement(14);
	s2.insertElement(13);
	s1.isEqualTo(s2);
	
	//Testando a isEqualTo (Condição falsa)
	s1.deleteElement(14);
	s1.isEqualTo(s2);
	
	//Testando o intersection
	s3.intersection(s1,s2);
	s3.toSetString();
	
    }
}