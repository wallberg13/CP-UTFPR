/*
  Arquivo SQL destinado para criações de Tabelas dentro da base de dados da
  TGas
*/

create table TipoEndereco(
  id integer primary key,
  tipoEnd varchar(20)
) with (FILLFACTOR = 99)
  tablespace Tables_TGas;

create table Endereco(
  id bigserial primary key using index tablespace Index_TGas,
  ruaNome varchar(100) not null,
  bairro varchar(100) not null,
  complemento varchar(200) not null,
  numero numeric(4,0) not null,
  TIPO_EN integer not null,

  unique (ruaNome,numero)
  using index tablespace Index_TGas,

  constraint tipo_en_fk foreign key (TIPO_EN)
  references TipoEndereco (id)
) tablespace Tables_TGas;

create table Produtos(
  idProd integer primary key using index tablespace Index_TGas,
  descri varchar(255) not null,
  quant_Estoque integer not null,
  valor_Uni numeric(8,2),

  unique (descri)
  using index tablespace Index_TGas
) tablespace Tables_TGas;

-- ATE AQUI TUDO ESTÁ NO BANCO

create table TipoCargo(
  idCarg integer primary key,
  descri varchar(20) not null
) with (FILLFACTOR = 99)
  tablespace Tables_TGas;

create table Funcionario(
  idFunc serial primary key using index tablespace Index_TGas,
  nome varchar(255) not null,
  salarioTotal numeric(9,2) not null,
  numCartTrab numeric(9,0) not null, --Atributo Unique
  telefone numeric(14,0), -- Atributo Unique
  CARGO_ID integer not null,

  constraint tipo_car_fk foreign key (CARGO_ID)
  references TipoCargo (idCarg),

  unique (numCartTrab)
  using index tablespace Index_TGas,

  unique (telefone)
  using index tablespace Index_TGas
) tablespace Tables_TGas;

create table TipoVenda(
  idTVend integer primary key,
  descr varchar(20) not null
) with (fillfactor = 99)
  tablespace Tables_TGas;

/*
  Tabelas com dependentes

  Tratar de colocar todas as chaves primarias na tablespace
  de indices.
*/
create table Cliente(
  idCli bigserial primary key using index tablespace Index_TGas,
  nome varchar(255) not null,
  CPF numeric(11,0) not null, -- Atributo Unique
  RG numeric(11,0) not null, -- Unique junto com EstRG
  EstRG varchar(3) not null, -- Unique junto com RG
  telefone numeric(14,0) not null, -- Unique
  limiteAPrazo integer not null default 1,
  dataCadastro date not null, -- Data do dia que foi cadastrado
  dataNasc date not null, -- Outra data
  ID_End integer not null,

  constraint endereco_cli_fk foreign key (ID_End)
  references Endereco (id),

  unique (RG,EstRG)
  using index tablespace Index_TGas,

  unique (CPF)
  using index tablespace Index_TGas

) tablespace Tables_TGas;

-- Novo savepoint

create table Venda(
  idVenda bigserial primary key using index tablespace Index_TGas,
  dataVenda date not null,
  valor numeric(9,2) not null,
  numFicha numeric(9,0) not null,
  tipoVenda integer not null,
  id_clie integer not null,
  id_Func integer not null,
  status varchar(255) not null,


  unique (numFicha)
  using index tablespace Index_TGas,

  constraint clie_venda_fk foreign key (id_clie)
  references Cliente (idCli),

  constraint func_vend_fk foreign key (id_Func)
  references Funcionario (idFunc),

  constraint tip_vend_fk foreign key (tipoVenda)
  references TipoVenda (idTVend)

) tablespace Tables_TGas;

create table ProdutVenda(
  quant integer not null,
  valor_total numeric(9,2) null,
  idProd integer,
  idVend integer,

  primary key (idVend,idProd),

  constraint prod_venda_fk foreign key (idVend)
  references Venda (idVenda),

  constraint prodD_venda_fk foreign key (idProd)
  references Produtos (idProd),

  unique (idProd, idVend)
  using index tablespace Index_TGas

) tablespace Tables_TGas;

/**
  Tabelas que serão preenchidas em triggers por inserção na
  tabela de vendas.
 */
create table ContasReceber(
  idConta bigserial primary key using index tablespace Index_TGas,
  dataParaReceber date not null,
  valor numeric(9,2) not null,
  idFunc integer null,
  idVend integer not null,
  idClie integer not null,

  constraint func_cont foreign key (idFunc)
  references Funcionario (idFunc),

  constraint vend_cont foreign key (idVend)
  references Venda (idVenda),

  constraint clie_cont foreign key (idClie)
  references Cliente (idCli)

) tablespace Tables_TGas;



create table Caixa(
  idMov bigserial primary key using index tablespace Index_TGas,
  descricao varchar(255) not null, -- Descrição do movimento
  valor numeric(9,2) not null,
  dataMov date not null,
  idVend integer not null,

  constraint vend_caixa foreign key (idVend)
  references Venda (idVenda)

) tablespace Tables_TGas;

/*
  Arquivo SQL destinado para criações de Tuplas dentro da base de dados da
  TGas
*/

/* Insert em tabelas que nunca irão mudar*/
insert into TipoEndereco values (1,'Travessa'), (2,'Rua'), (3,'Avenida'),(4,'Condominio');
insert into TipoVenda values (1,'A vista'), (2,'A prazo');
insert into TipoCargo values (1,'Gerente'),(2,'Entregador'),(3,'Cobrador'),(4,'Atendente');


-->>>> Lembrar de inserir só uma vez, ou colocar codigo pra ele
insert into Produtos values (1,'MEIOTA',999,20.00),(2,'P45',899,160.00),(3,'Vazilhame',100,100.00),(4,'P13',999,60.00),(5,'P10',500,45.00);


/*
  RANGES:
  TIPO_ENDERECO: 1 - 4;
  ENDERECO: 1 - 9999;
  CLIENTES: 1 - 20000;
  TIPO_CARGO: 1 - 4;
  FUNCIONARIO: 1 - 100;
  VENDAS: 1 - 200000;
  TIPO_VENDA: 1 - 2;
  PRODUTO: 1 - 5;

  Em produto Venda:
  De 1 - 100000

*/

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
  if (new.tipoVenda = 1) then -- Venda a vista, então popula Caixa
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
