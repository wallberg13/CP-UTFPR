public class EmailSimplorio{

    private String de;
    private String para;
    private String assunto;
    private String mensagem;
    
    public EmailSimplorio(String user,String para,String assunto,String mensagem){
	this.de = user;
	this.para = para;
	this.assunto = assunto;
	this.mensagem = mensagem;
    }
    
    public void mostra_email(int i,String user){
	
	System.out.println("\n\n"+i+"°\tOrigem: "+de);
	System.out.println("\tAssunto: "+assunto);

    }

    public String get_para(){
	return this.para;
    }
    
    public String get_mensagem(){
	return this.mensagem;
    }
}