/*
 1 - COM UNION
*/
select c.NOMECLIENTE, p.VALOR, v.NOMEVENDEDOR from Pedido p
inner join Cliente c
on c.CODCLIENTE = p.REFCLI
inner join Vendedor v
on v.CODVENDEDOR = p.REFVEND
where p.DATA between '01/01/2015' and '11/29/2016' and v.CODVENDEDOR = 1

union

select c.NOMECLIENTE, p.VALOR, v.NOMEVENDEDOR from Pedido p
inner join Cliente c
on c.CODCLIENTE = p.REFCLI
inner join Vendedor v
on v.CODVENDEDOR = p.REFVEND
where p.DATA between '01/01/2015' and '11/29/2016' and v.CODVENDEDOR = 4
order by 1;

/*
 1 - SEM UNION
*/
select c.NOMECLIENTE, p.VALOR, v.NOMEVENDEDOR from Pedido p
inner join Cliente c
on c.CODCLIENTE = p.REFCLI
inner join Vendedor v
on v.CODVENDEDOR = p.REFVEND
where p.DATA between '01/01/2015' and '11/29/2016' and (v.CODVENDEDOR = 1 or v.CODVENDEDOR = 4)
order by 1;

/*
 2 - Total Pedidos Cliente
*/
select count(p.CODPEDIDO) TotalPedidosCliente, c.NOMECLIENTE from Pedido p
inner join Prazo pz
on pz.CODPRAZO = p.REFPRAZO 
inner join Cliente c
on c.CODCLIENTE = p.REFCLI
where upper(pz.DESCRICAOPRAZO) = upper('a vista')
group by c.NOMECLIENTE
order by count(p.CODPEDIDO) desc; 

/*
 3 - MAIS COMPLICADA
*/

select c.CODCLIENTE, c.NOMECLIENTE, v.NOMEVENDEDOR, count(p.CODPEDIDO) TotalPedidosClienteVendedor, sum(p.VALOR) Montante
from Pedido p
inner join Cliente C
on c.CODCLIENTE = p.REFCLI
inner join Vendedor v
on v.CODVENDEDOR = p.REFVEND
group by c.CODCLIENTE, c.NOMECLIENTE, v.NOMEVENDEDOR
having count(p.CODPEDIDO) > 20
order by 2,4;

/*
 4 - Sum vendas do cliente
*/
select c.codCliente, c.nomeCliente, sum(p.valor) from Pedido p
right join Cliente c
on c.CODCLIENTE = p.REFCLI
group by c.CODCLIENTE,c.NOMECLIENTE;
