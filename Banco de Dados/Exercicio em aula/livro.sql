/* Criando a tabela */
create table livro(
    codigo integer not null,
    titulo varchar(50) not null,
    pg integer not null,
    ano integer not null,
    editora varchar(50) not null,
    assunto varchar(50) not null,
    autor varchar(50) not null,
    genero varchar(50) not null    
);
commit;

/* 1 - Defina uma chave primaria p/ livro */
alter table livro add primary key(codigo);
commit;

/* 2 - Insira um atributo em livro*/
alter table livro add cod_editora integer;
commit;

/* 3 - Altere o tipo de um atributo */
alter table livro alter titulo type varchar(60);
commit;

/* 4 - Altere o nome de um atributo */
alter table livro alter autor to autor_livro;
commit;

/* 5 - Remova um atributo de um livro */
alter table livro drop genero;
commit;