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
