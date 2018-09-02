/*
  Arquivo SQL destinado para criações de Triggers dentro da base de dados da
  TGas
*/

/*
  Triggers que iram popular ContasReceber e
  Caixa
*/
create or replace function populaContCaix()
returns trigger
as $$
begin
  if (new.tipoVenda = 1) thn -- Venda a vista, então popula Caixa
    insert into Caixa (descricao, valor, dataMov, idVend)
    values ('Venda a vista',new.valor,new.dataVenda, new.idVenda);
    return new;
  else -- Venda é a prazo, logo, popula contasreceber
    insert into ContasReceber (dataParaReceber, valor, idVend, idClie)
    values (new.dataVenda + 30, new.valor + new.valor*0.1, new.idVenda, new.id_clie); --Fazer soma de dias
    return new;
  end if;
  return null;
end;
$$ language plpgsql;

create trigger TrigVendaPop after insert on Venda
for each row execute procedure populaContCaix();

/**
  Trigger para ProdutVenda para calcular o valor total dos produtos.

  DUVIDAS NESSA TRIGGER
 */
create or replace function procCalcTotal()
returns trigger
as $$
declare
  valor numeric;
begin
  select p.valor_Uni into valor from Produtos as p
  where p.idProd = new.idProd;
  new.valor_total = valor*new.quant;
  return new;
end;
$$ language plpgsql;

/**
  Ao invés de fazer o insert normal, personaliza o insert.
*/
create trigger TrigCalcProdVend
before insert on ProdutVenda
for each row execute procedure procCalcTotal();
