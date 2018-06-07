/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio03;

/**
 *
 * @author sir-berg
 */
public interface IDNS {
    
    /**
     * Metodo que faz o cadastro de um nome de domínio.
     * Formato de requisicao: bind <dominio> <ip> <porta>
     * Resposta: "Ok. Domínio Registrado" ou "Erro: domínio já está registrado"
     * @param dominio
     * @param IP
     * @param porta
     * @return 
     */
    public String bind(String dominio, String IP, int porta);
    
    /**
     * Faz a resolução de um nome.
     * Requisição: lookup <dominio>
     * Resposta: <ip> <porta> ou "Erro: Domínio não registrado"
     * @param dominio
     * @return 
     */
    public String lookup(String dominio);
    
    /**
     * Faz a remoção de um nome de domínio
     * Requisição: unbind <dominio>
     * Resposta: "OK. Dominio Removido" ou "Erro: dominio não existe"
     * @param dominio
     * @return 
     */
    public String unbind(String dominio);
    
    /**
     * Lista todos os nomes de domínio registrados
     * Requisição: list
     * Resposta: <dominio1>, <dominio2>
     * @return 
     */
    public String[] list();
    
}
