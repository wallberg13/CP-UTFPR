/**
  Alguns Inserts Basicos, em relação a coisas que já deve ter no banco, como idiomas,
  e tipos de texto.
  Autores e titulos de textos deveram ser gerados automaticamente.
*/

insert into idioma (nome) values (upper('ingles'));
insert into idioma (nome) values (upper('postugues'));
insert into idioma (nome) values (upper('frances'));

insert into tipo_texto (nome) values (upper('noticia'));
insert into tipo_texto (nome) values (upper('livro'));
insert into tipo_texto (nome) values (upper('revista'));
insert into tipo_texto (nome) values (upper('artigo'));

insert into autor (nome) values (upper('teste01'));
insert into autor (nome) values (upper('teste02'));

commit;

insert into palavra (nome,fk_idioma) values (upper('palavra01'),1);
insert into palavra (nome,fk_idioma) values (upper('palavra02'),1);
insert into palavra (nome,fk_idioma) values (upper('palavra03'),1);
insert into palavra (nome,fk_idioma) values (upper('palavra04'),1);

insert into palavra (nome,fk_idioma) values (upper('palavra05'),2);
insert into palavra (nome,fk_idioma) values (upper('palavra06'),2);
insert into palavra (nome,fk_idioma) values (upper('palavra07'),2);
insert into palavra (nome,fk_idioma) values (upper('palavra08'),2);
insert into palavra (nome,fk_idioma) values (upper('palavra09'),3);

commit;

insert into texto (nome, fk_tipTex, fk_autor, fk_idioma)
values (upper('texto01'),1,1,1);

insert into texto (nome, fk_tipTex, fk_autor, fk_idioma)
values (upper('texto02'),1,1,2);

commit;

insert into palavra_texto (fk_text,fk_pal) values (1,1);
insert into palavra_texto (fk_text,fk_pal) values (1,2);
insert into palavra_texto (fk_text,fk_pal) values (1,3);
insert into palavra_texto (fk_text,fk_pal) values (1,4);

commit;

insert into pal_tex_prox (fk_palTex, fk_pal) values (1,2);
insert into pal_tex_prox (fk_palTex, fk_pal) values (2,3);
insert into pal_tex_prox (fk_palTex, fk_pal) values (3,4);
insert into pal_tex_prox (fk_palTex, fk_pal) values (4,1);
insert into pal_tex_prox (fk_palTex, fk_pal) values (1,3);
insert into pal_tex_prox (fk_palTex, fk_pal) values (1,4);
commit;

-- Só para limpar o banco
delete from pal_tex_prox;
delete from palavra_texto;
delete from texto;
delete from palavra;
delete from idioma;
delete from autor;
