import javax.swing.JOptionPane;

public class Terceiro{

	public static void main(String[] args){
		String texto = JOptionPane.showInputDialog("Entre com um numero: ");
		int numero = Integer.parseInt(texto); //Convertendo String para int
		JOptionPane.showMessageDialog(null,numero);
	}
}