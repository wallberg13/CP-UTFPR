/* Consulta que seleciona o nome do
funcionario e o valor de uma dada venda*/
explain select f.nome, v.valor from funcionario f
inner join venda v on v.id_func = f.idfunc
where v.idvenda = 10;


/*Consulta que seleciona todos os clientes que possuem um débito crítico (acima de 1000 reais)*/
explain select c.nome, r.valor from cliente c
inner join contasreceber r on r.idclie = idcli
where r.valor>1000;

/*Consulta que seleciona o nome, o bairro, a rua e o numero do cliente*/
explain select c.nome, e.bairro, e.ruanome,e.numero from cliente c
inner join endereco e on e.id = c.id_end
where c.nome = 'Jusefa';

/*Consulta que seleciona a descricao dos produtos e a quantidade em estoque dos produtos que possuem menos de 10 unidades*/
explain select descri,quant_estoque from produtos
where quant_estoque<10;

/*Consulta que seleciona o id, nome e a data de cadastro de clientes que possuem associação a mais de 5 anos*/
explain select idcli, nome, datacadastro from cliente
where datacadastro<='2012-06-16';
