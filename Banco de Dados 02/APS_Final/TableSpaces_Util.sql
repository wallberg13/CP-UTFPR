/*
  Criação de Tablespaces para os modulos chave do sistema,
  para caso as maquinas derem 'pau', não correr o risco de perder tudo.

  Então sera criado tablespaces para:

  -Logs
  -Index
  -Tabelas

*/
create tablespace Logs_TGas location '/var/lib/postgres/data/TGas/Logs_TGas';
create tablespace Index_TGas location '/var/lib/postgres/data/TGas/Index_TGas';
create tablespace Tables_TGas location '/var/lib/postgres/data/TGas/Tables_TGas';

/*
  Usuarios autorizados para fazer qualquer alteração no banco
*/
