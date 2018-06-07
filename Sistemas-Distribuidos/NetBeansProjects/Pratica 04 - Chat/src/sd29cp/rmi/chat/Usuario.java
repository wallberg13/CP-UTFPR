package sd29cp.rmi.chat;

import java.io.Serializable;

public class Usuario implements Serializable {
    private String nome;
    private ICallback callback;

    public Usuario(String nome, ICallback callback) {
        this.nome = nome;
        this.callback = callback;
    }

    public ICallback getCallback() {
        return callback;
    }

    public void setCallback(ICallback callback) {
        this.callback = callback;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    @Override
    public String toString() {
        return this.nome;
    }

}
