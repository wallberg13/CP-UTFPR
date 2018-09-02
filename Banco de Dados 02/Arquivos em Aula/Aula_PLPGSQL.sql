-- Criando Funções

create or replace function soma (a integer, b integer)
returns integer as $$
begin 
	return a + b;
end;
$$ language plpgsql;

select soma(2,3);

create or replace function soma01 (integer, integer)
returns integer as $$
declare
	param1 alias for $1;
	param2 alias for $2;
begin
	return param1 + param2;
end;
$$ language plpgsql;

select soma01(03,40);

-- Function 03 --> Mais de um retorno

create function teste03 (a integer, b integer, out somaX integer, out prod integer)
as $$
begin
	somaX := a + b;
	prod := a * b;
end;
$$ language plpgsql;

select teste03(3,4);

-- Function 04 --> Função que retorna tabela

create table vendas(
	itemno integer,
	quantidade integer,
	preco numeric
);

create or replace function Vendas (itemID int)
returns table (quantidade int, total numeric) as $$
begin
	return query 
		select v.quantidade, v.quantidade*v.preco
		from vendas as V
		where itemno = itemID;     
end;
$$ language plpgsql;

select * from vendas(1);

--> Funcao 04 - Função de fatorial
create function fatorial (n integer)
returns integer as $$
declare
	fat integer default 1;
begin
	for i in reverse n..1 loop
		fat := fat*i;
	end loop;
	return fat;
end;
$$ language plpgsql;

do $$ 
begin
	for i in 1..5 loop
		raise notice 'Fatorial( % ) = %',i, fatorial(i);
	end loop;
end $$;

--> Função 05 - SETOF e Return Next
create table aluno(
	ra INT,
	nome varchar,
	datanasc date
);

insert into aluno values (1,'Pedro', to_date('12-02-1995','DD-MM-YYYY'));
insert into aluno values (2,'Juca', to_date('20-03-1989','DD-MM-YYYY'));

create or replace function todos_alunos()
returns setof aluno as
$$
declare
	r aluno%rowtype;
begin
	for r in 
		select * from aluno where ra > 0
	loop
		-- pode-se fazer algum processamento aqui
		return next r; -- retorna tupla atual do SELECT
	end loop;
	return;		
end;
$$ language plpgsql;

select * from todos_alunos();

--> Função 06 - Calculando idade atual
create function get_idades()
returns table (nome varchar, idade double precision) as $$
begin
	return query 
		select A.nome, extract(year from age(A.datanasc)) 
		from aluno as A;
end;
$$ language plpgsql;

select nome, idade from get_idades();

--> IF .. THEN .. ELSE
do $$
declare
	reg integer;
begin
	select ra into reg from aluno where nome = 'Juca';
	if reg <> 0 then
		update aluno set datanasc = to_date('20-03-1950','DD-MM-YYYY') 
		where ra = reg;
	end if;
end $$


--> Vetores e Matrizes
create function scan_rows(int []) 
returns void as
$$
declare
	x int[];
begin
	foreach x slice 1 in array $1
	loop
		raise notice 'row = %', x;
	end loop;
end;
$$ language plpgsql;

select scan_rows(array[[1,2,3],[4,5,6],[7,8,9],[10,11,12]]);