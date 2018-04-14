public class Principal{
    public static void main(String[] args){
	Animal au = new Animal("meu","animal",true);
	au.imprime();
	
	Peixe px = new Peixe("esc",2.0,"da","peixinho",true);
	px.imprime();
	
	Mamifero mm = new Mamifero("200000 anos","macaco","chibatas",true);
	mm.imprime();
	
	Aves av = new Aves("rosa","potiagudo",true,"paparico","papaguaio",true);
	av.imprime();
    }	
}