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
