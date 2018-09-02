import java.util.Scanner;

public class Main{

    public static void main(String[] args){
	EmailSimplorio[] emails = new EmailSimplorio[10];
	Scanner teclado = new Scanner(System.in);
	menu_principal(emails,teclado);
    }
    
    public static void manda_email(EmailSimplorio emails[],Scanner teclado,String user){
	System.out.print("Digite o destinatario da mensagem: ");
	String para = teclado.nextLine();
	para = teclado.nextLine();
	
	System.out.print("Digite o assunto da mensagem: ");
	String assunto = teclado.nextLine();
	
	System.out.print("Digite a mensagem: ");
	String mensagem = teclado.nextLine();
	
	for(int i = 0; i < emails.length; i++){
	    if(emails[i] == null){
		emails[i] = new EmailSimplorio(user,para,assunto,mensagem);
		return;
	    }
	}
	System.out.println("Caixa de emails cheia");
    }
    
    public static void login(EmailSimplorio emails[], Scanner teclado){
	System.out.print("Digite o nome do usuario: ");
	String user = teclado.nextLine();
	user = teclado.nextLine();
	int resp = 0;
	
	do{
	    System.out.println("\n\n/***Menu do Usuario***\\");
	    System.out.println("Logado como: "+user);
	    System.out.println("01 - Escrever Email.");
	    System.out.println("02 - Ver todos os emails recebidos. ");
	    System.out.println("03 - Ler Email. ");
	    System.out.println("00 - Logout. ");
	    System.out.print("Digite a sua Resposta: ");
	    resp = teclado.nextInt();
	    
	    switch(resp){
		case 1:
		    manda_email(emails,teclado,user);
		    break;
		case 2:
		    lista_email(emails,user);
		    break;
		case 3:
		    abre_email(emails,user,teclado);
		    break;
	    }
	}while(resp != 0);
	System.out.println("\n\n***Logout Feito com Sucesso***");
    }
    
    public static void lista_email(EmailSimplorio emails[],String user){
	
	for(int i = 0;i<emails.length;i++){
	    if(emails[i] != null && user.equals(emails[i].get_para())){
		emails[i].mostra_email(i,user);
	    }
	}
    }
    
    public static void abre_email(EmailSimplorio emails[],String user, Scanner teclado){
	int j = 0;
	for(int i = 0;i<emails.length;i++){
	    if(emails[i] != null && user.equals(emails[i].get_para())){
		emails[i].mostra_email(i,user);
		j++;
	    }
	}
	if(j!=0){
	    System.out.print("\nQual email deseja abrir? \nDigite o codigo: ");
	    int i = teclado.nextInt();
	    
	    if(i>=0 && i < emails.length && user.equals(emails[i].get_para())){
		emails[i].mostra_email(i,user);
		System.out.println("\tMensagem: \n\t\t"+emails[i].get_mensagem());
	    }else{
		System.out.println("Não é possivel abrir o email selecionado.");
	    }
	}else{
	    System.out.println("\n\nEmail Vazio.\n\n");
	}
    }
    
    public static void menu_principal(EmailSimplorio emails[],Scanner teclado){
	int resp = 0;
	do{
	    System.out.println("\n\n/***Menu Principal***\\");
	    System.out.println("01 - Login.");
	    System.out.println("00 - Sair.");
	    System.out.print("Digite a sua resposta: ");
	    resp = teclado.nextInt();
	    
	    switch(resp){
		case 1:
		    login(emails,teclado);
		    break;
	    }
	}while(resp != 0);
	System.out.println("Flw Jovem \n\n\n");
    }
}