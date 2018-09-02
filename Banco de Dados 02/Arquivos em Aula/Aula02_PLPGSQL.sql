/*
	Uso de cursor
*/
do $$
declare
	c_alunos cursor for select * from aluno;
	v_aluno record;
begin
	open c_alunos; -- Abre o cursor e obtém o conjunto-resposta
	loop
		fetch c_alunos into v_aluno; -- Recupera uma tupla
		-- Sai do laco quando não tem mais tuplas:
		exit when v_aluno is null;
		raise notice 'Ra: %, Nome: %', v_aluno.ra, v_aluno.nome;
	end loop; 
	close c_alunos; -- Fecha o cursor
end; $$
language plpgsql

/*
	Uso do cursor dentro de um laço for
	Não funciona pq não tem os atributos suficientes na tabela
*/
do $$
declare
	c_aluno cursor for select RA, Nome, Extract(year from age(Datanasc)) 
	as Idade from Aluno
	where Cidade = 'Pato Branco';
begin
	for aluno in c_aluno loop
		raise notice 'Idade de %: %', alu.Nome, alu.Idade;
	end loop;
end; $$
language plpgsql;

/* 
	Exemplo de Funcao e Trigger
*/
create table aluno2(
	nome varchar(200);
	datanasc date;
);

create or replace function atualizaAluno2()
return trigger as $$
begin
	insert into aluno2 values (NEW.nome, NEW.datanasc);
	return NEW;
end;
$$ language plpgsql;

create trigger TrigAluno2 befone insert on Aluno
for each row execute procedure atualizaAluno2();

/*
	Criando tabela de logs
*/
create table func(
	nome varchar,
	salario numeric
);

create table audit_func(
	operacao char,
	data timestamp,
	usuario varchar,
	nomefunc varchar,
	salario numeric
);

create or replace function process_func_audit()
returns trigger as $func_audit$
begin
	if (TG_OP = 'DELETE') then
		insert into audit_func select 'D', now(), user, old.*;
		return old;
	elsif (TG_OP = 'UPDATE') then
		insert into audit_func select 'U', now(), user, new.*;
		return new;
	elsif (TG_OP = 'INSERT') then
		insert into audit_func select 'I', now(), user, new.*;
		return new;
	end if;
	return null; -- Resultado é ignorado pois será uma AFTER trigger
end;
$func_audit$ 
language plpgsql;

create trigger func_audit
after insert or update or delete on func
for each row execute procedure process_func_audit();











