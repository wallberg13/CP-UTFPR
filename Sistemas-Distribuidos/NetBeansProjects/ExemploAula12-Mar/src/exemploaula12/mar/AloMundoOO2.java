package exemploaula12.mar;

public class AloMundoOO2 {
    private IAloMundo alo = null;

    public AloMundoOO2() {
        alo = new AloMundoImpl();
    }
    
    public static void main(String[] args) {
        AloMundoOO2 obj = new AloMundoOO2();
        obj.iniciar();
    }
    
    private void iniciar() {
        System.out.println(alo.digaAloMundo(10));
    }
}
