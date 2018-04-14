public class IntergerSet{
    private boolean bool[] = new boolean[101];
    
    public IntergerSet(){
	for(int i = 0; i < 101; i++)
	    bool[i] = false;
    }
    
    public IntergerSet(int i){
	for(int j = 0; j < 101; j++)
	    bool[j] = false;
	if(i<101)
	    bool[i] = true;
    }
    
    public void union(IntergerSet s1,IntergerSet s2){
	for(int i = 0; i < 101; i++){
	    this.bool[i] = s1.bool[i]||s2.bool[i];
	}
    }
    
    public void intersection(IntergerSet s1,IntergerSet s2){
	for(int i = 0; i < 101; i++)
	    this.bool[i] = s1.bool[i]&&s2.bool[i];
    }
    
    public void insertElement(int i){
	if(i>=0 && i <= 100)
	    bool[i] = true;
    }
    
    public void deleteElement(int i){
	if(i>=0 && i <= 100)
	    bool[i] = false;
    }
    
    public void toSetString(){
	int i;
	for(i = 0; i < 101; i++){
	    if(bool[i] == true)
		break;
	}
	if(i == 101){
	    System.out.println("--");
	    return;
	}
	String g = "";
	for(i = 0; i < 101; i++){
	    if(bool[i] == true)
		g += i + " ";
	}
	System.out.println(g);
    }
    
    public void isEqualTo(IntergerSet s1){
	int i;
	for(i = 0; i < 101; i++){
	    if(this.bool[i] != s1.bool[i])
		break;
	}
	
	if(i == 101)
	    System.out.println("Os conjuntos são iguais.");
	else
	    System.out.println("Os conjuntos são diferentes.");
    }
}