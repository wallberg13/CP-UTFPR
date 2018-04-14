/*
  Arquivo SQL destinado para criações de Indices dentro da base de dados da
  TGas
*/

/**
  Consultas corriqueiras, saber qual foram os produtos para
  determinada venda

  Qual Funcionario que Realizou determinada Venda

  Quantidade de compras que o Cliente X Possui


*/


create index atendente on funcionario(idfunc,nome)
where cargo_id =  4;
create index vd_fc on venda(idvenda,id_func,valor);

create index critica on contasreceber(idclie) where valor>1000;
create index cli_crit on cliente(idcli,nome);

create index endcli on endereco(ruanome,numero,bairro);

create index fora on produtos(descri,quant_estoque) where quant_estoque <10;

create index socio on cliente(idcli,nome) where datacadastro <= '2012-06-16';
