package com.example.sir_berg.prova01_dispositivos;

public class TaxaMetaBasal {
    private double peso; // Em KG
    private Integer altura; // em CM
    private char sexo; // M ou F
    private Integer idade; // 0 -- 120
    private Integer cod; // 1 - 5 -- Switch case.

    /**
     * O objeto sera criado na proxima tela e esse mesmo objeto sera compartilhado pelas
     * demais teclas.
     *
     * Entao inicialmente e dado um valor default.
     **/
    public TaxaMetaBasal(Double peso, Integer altura, char sexo, Integer idade, Integer cod){
        this.peso = peso;
        this.altura = altura;
        this.sexo = sexo; // Indefinido
        this.idade = idade;
        this.cod = cod;
    }

    public double calc(){
        double resp = 0.0, aux;
        if(this.sexo == 'M' || this.sexo == 'm'){
            aux = 66 + (13.7 * this.peso) + (5.0 * this.altura) - (6.8 * this.idade);
        }else{ // O aplicativo nao ira deixar que seja inserido outro tipo de sexo.
            aux = 655 + (9.6 * this.peso) + (1.8 * this.altura) - (4.7 * idade);
        }

        switch (cod){
            case 1:
                resp = aux * 1.2;
                break;
            case 2:
                resp = aux * 1.375;
                break;
            case 3:
                resp = aux * 1.55;
                break;
            case 4:
                resp = aux * 1.725;
                break;
            case 5:
                resp = aux * 1.9;
                break;
            default:
                break;
        }

        return resp;
    }

}
