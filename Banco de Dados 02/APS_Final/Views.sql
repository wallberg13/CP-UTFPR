/*
  Arquivo SQL destinado para criações de Views de auditoria dentro da base de dados da
  TGas
*/

/*
  Visão para mostrar a ultima atualização de salario
*/
create view func_salario as
select f.idFunc, f.nome, f.salarioTotal, max(fa.data) from Funcionario as f
inner join Func_Audit as fa
on fa.idFunc = f.idFunc
group by (f.idFunc, f.nome, f.salarioTotal);

/**
  Como já tem a trigger que é disparada depois que um evento de delete, insert ou update
  em cima da tabela funcionario, ao dá um update na tabela de funcionario, automaticamente
  aquela trigger em cima da tabela é disparada.

*/
create or replace function Proce_Func_Sal_View()
returns trigger
as $$
begin
  update Funcionario set salarioTotal = new.salarioTotal where idFunc = old.idFunc;
  return new;
end;
$$ language plpgsql;

create trigger Trig_Func_Sal_View
instead of update on func_salario
for each row execute procedure Proce_Func_Sal_View();


/**
  Visão para Clientes, o que pode acontecer com eles é mudanca de limiteAPrazo,
  telefone e endereco
*/

create view clie_end_view as
select c.idCli, c.nome, e.ruaNome, e.numero, e.bairro from Cliente c
inner join Endereco as e
on e.id = c.ID_End;

create or replace function Proce_Clie_View()
returns trigger
as $$
declare
  idEndereco integer;
begin
  if (TG_OP = 'UPDATE') then
    if(new.ruaNome is not null and new.numero is not null) then
      select id into idEndereco from Endereco
      where ruaNome = new.ruaNome and numero = new.numero;
      if(not FOUND)
        raise notice 'ESTOU AQUIII';
      end if;
      update Cliente set ID_End = idEndereco
      where idCli = old.idCli;
    end if;
    return new;
  elsif (TG_OP = 'DELETE') then
    delete from Cliente where idCli = old.idCli;
    return new;
  end if;
  return null;
end;
$$ language plpgsql;

create trigger Trig_Clie_View
instead of update or delete on clie_end_view
for each row execute procedure Proce_Clie_View();
