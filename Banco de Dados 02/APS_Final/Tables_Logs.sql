/*
  Arquivo SQL destinado para criações de Tabelas de auditoria dentro da base de dados da
  TGas
*/

create table Func_Audit(
  operacao char(1) not null,
  usuario text not null,
  idFunc integer not null,
  nomeFunc text not null,
  salarioTotal numeric(9,2) not null,
  telefone numeric (14,0) not null,
  CARGO_ID integer not null,
  data timestamp not null
) tablespace Logs_TGas;

create table Clie_Audit(
  operacao char(1) not null,
  usuario text not null,
  data timestamp not null,
  idClie integer not null,
  nome varchar(255) not null,
  telefone numeric(14,0) not null,
  limiteAPrazo integer not null,
  ID_End integer not null
) tablespace Logs_TGas;


create or replace function Process_Clie_Audit()
returns trigger
as $$
begin
  if(TG_OP = 'DELETE') then
    insert into Clie_Audit
    values ('D', user, now(), old.idCli, old.nome, old.telefone, old.limiteAPrazo, old.ID_End);
    return old;
  elsif (TG_OP = 'UPDATE') then
    insert into Clie_Audit
    values ('U', user, now(), new.idCli, new.nome, new.telefone, new.limiteAPrazo, new.ID_End);
    return new;
  elsif (TG_OP = 'INSERT') then
    insert into Clie_Audit
    values ('I', user, now(), new.idCli, new.nome, new.telefone, new.limiteAPrazo, new.ID_End);
    return new;
  end if;
  return null;
end;
$$ language plpgsql;

create trigger Trig_Clie_Audit
after insert or update or delete on Cliente
for each row execute procedure Process_Clie_Audit();


/**
  Trigger para essas tabelas
*/
create or replace function Process_Funcio_Audit()
returns trigger
as $$
begin
  if (TG_OP = 'DELETE') then
    insert into Func_Audit values
    ('D', user, old.idFunc, old.nome, old.salarioTotal, old.telefone, old.CARGO_ID, now());
    return old;
  elsif (TG_OP = 'UPDATE') then
    /** Cada para campo alterado na tabela, uma nova entrada em auditoria */
    if (new.salarioTotal is not null) then
      insert into Func_Audit values
      ('U', user, old.idFunc, old.nome, new.salarioTotal, old.telefone, old.CARGO_ID, now());

    elsif (new.telefone is not null) then
      insert into Func_Audit values
      ('U', user, old.idFunc, old.nome, old.salarioTotal, new.telefone, old.CARGO_ID, now());

    elsif (new.CARGO_ID is not null) then
      insert into Func_Audit values
      ('U', user, old.idFunc, old.nome, old.salarioTotal, old.telefone, new.CARGO_ID, now());

    end if;
    return new;
  elsif (TG_OP = 'INSERT') then
    insert into Func_Audit values
    ('I', user, new.idFunc, new.nome, new.salarioTotal, new.telefone, new.CARGO_ID, now());
    return new;
  end if;
  return null;
end;
$$
language plpgsql;

create trigger TrigFuncio_Audit
after insert or update or delete on Funcionario
for each row execute procedure Process_Funcio_Audit();
