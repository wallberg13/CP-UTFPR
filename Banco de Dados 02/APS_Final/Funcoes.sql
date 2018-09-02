create or replace function mostraVendedor (numVenda integer)
returns varchar as $$
declare
	nomeee varchar;
begin
	select F.nome into nomeee from venda as V left join Funcionario as F
	on V.id_func = F.idfunc
	where V.idvenda = numVenda;
	return nomeee;
end;
$$ language plpgsql;
----------------------------------------------------------------
select mostraVendedor(5)
------\-----------------\--------------------\--------------\-----

create or replace function listaVendasCliente(nomeCliente varchar)
returns table (idC bigint, nomeC varchar, idV bigint, valV numeric(9,2)) as $$
begin
	return query select C.idcli, C.nome, V.idvenda, V.valor
	from cliente as C inner join Venda as V
	on V.id_clie = C.idcli
	where nomeCliente = C.nome;
end;
$$ language plpgsql;

----------------------------------------------------------------

select listaVendasCliente('Alexis Z. Quinn')

------\-----------------\--------------------\--------------\-----

create or replace function totalCompraCliente(nomeCliente varchar)
returns numeric as $$
declare valTot numeric;
begin
	select C.idcli, C.nome, sum(V.valor) into valTot
	from cliente as C inner join Venda as V
	on V.id_clie = C.idcli
	where nomeCliente = C.nome
	group by (C.idcli, C.nome);
	return valTot;
end;
$$ language plpgsql;

----------------------------------------------------------------
select totalCompraCliente('Alexis Z. Quinn')

------\-----------------\--------------------\--------------\-----

create or replace function totalVendaVendedor(nomeVendedor varchar)
returns table(nomeVend varchar, valorTotal numeric) as $$
declare valTot numeric;
begin
	return query
	select F.nome, sum(V.valor)
	from funcionario as F inner join Venda as V
	on V.id_func = F.idfunc
	where nomeVendedor = F.nome
	group by F.nome;
end;
$$ language plpgsql;

----------------------------------------------------------------
select totalVendaVendedor('Bevis E. Gross')
------\-----------------\--------------------\--------------\-----
