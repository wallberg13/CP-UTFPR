/**
  Consultas de variados tipo, que depois irá ser transformadas em funções
  em C que poderá ser feito via um interface simples.
*/

/* 1° - Autores que escrevem textos do tipo "x" */
select a.nome Nome_Autor,tt.nome Nome_Tipo from autor a, texto t, tipo_texto tt
where t.fk_tipTex = tt.idTipText and a.idAut = t.fk_autor
and upper(tt.nome) = upper('x');

/* 2° - Quantas palavras diferentes tem no texto "x" */
select count(pt.idPalTex) Quant_Pal from texto t, palavra_texto pt
where t.idTex = pt.fk_text and upper(t.nome) = upper('x');

/* 3° - Quantas palavras o autor "x" já escreveu */
select count(pt.idPalTex) Quant_Pal_Autor from texto t, palavra_texto pt, autor a
where a.idAut = t.fk_autor and pt.fk_text = t.idTex and upper(a.nome) = upper('x');

/* 4° - Quantas palavras do tipo de texto "x" já foram escritas */
select count(pt.idPalTex) Quant_Pal_Tipo from texto t, tipo_texto tt, palavra_texto pt
where t.fk_tipTex = tt.idTipText and pt.fk_text = t.idTex and upper(tt.nome) = upper('x');

/* 5° - Liste todas as palavras (cod e descr) e suas proximas de todos os textos */
select p1.idPal idPalavra, p1.nome Nome_Palavra_Atual,
p2.idPal idPalavraProx, p2.nome Nome_Palavra_Atual
from palavra p1, palavra p2, pal_tex_prox ptp, palavra_texto pt
where pt.fk_pal = p1.idPal and p2.idPal = ptp.fk_pal and pt.idPalTex = ptp.fk_palTex;

/* 6° - Liste todas as palavras do idioma "x" */
select p.idPal ,p.nome,idi.nome Idioma from palavra p, idioma idi
where p.fk_idioma = idi.idIdioma and upper(idi.nome) = upper('x');

/* 7° - Liste todos os textos do idioma x */
select t.nome Nome_Texto, id.nome IDIOMA from idioma id, texto t
where t.fk_idioma = id.idIdioma and upper(id.nome) = upper('x');

/* 8° - Liste o(s) idiomas que um autor "x" escreve */
select a.nome AUTOR, id.nome IDIOMA from idioma id, texto t, autor a
where a.idAut = t.fk_autor and t.fk_idioma = id.idIdioma and upper(a.nome) = upper('x');

/* 9° - Quantos textos o idioma "x" possui */
select count(t.idTex) Quant_text from idioma id, texto t
where t.fk_idioma = id.idIdioma and upper(id.nome) = upper('x');

/* 10° - Mostre todas as palavras que foram escritas para um tipo de texto "x" */
select p.nome Palavra, tt.nome Tipo_Texto from tipo_texto tt, texto t, palavra_texto pt, palavra p
where tt.idTipText = t.fk_tipTex and pt.fk_text = t.idTex and pt.fk_pal = p.idPal
and upper(tt.nome) = upper('x');

/* 11° - Mostre todas as palavras que o autor "x" já escreveu */
select p.nome Palavra, a.nome Autor from autor a, texto t, palavra_texto pt, palavra p
where a.idAut = t.fk_autor and t.idTex = pt.fk_text and pt.fk_pal = p.idPal
and upper(a.nome) = upper('x');

/* 12° - Mostre quantas palavras cada idioma possui */
select count(p.idPal), i.nome from palavra p, idioma i
where i.idIdioma = p.fk_idioma
group by i.nome;

/* 13° - Mostre quantas palavras cada idioma possui, exibindo aqueles que possui
         pelo menos 'x' palavras */
select count(p.idPal),i.nome from palavra p, idioma i
where i.idIdioma = p.fk_idioma
group by i.nome
having count(p.idPal) > x;

/* 14° - Mostre os textos que possui pelo menos 'x' palavras */
select t.nome Texto, count(pt.fk_pal) from texto t, palavra_texto pt
where t.idTex = pt.fk_text
group by t.nome
having count(pt.fk_pal) > x;

/* 15° - Mostre  a quantidade de palavras que cada autor escreveu*/
select count(pt.idPalTex) Quant_Pal_Autor, a.nome from texto t
inner join autor a
on a.idAut = t.fk_autor
inner join palavra_texto pt
on pt.fk_text = t.idTex
group by a.nome;

/* 16° - Quantas vezes a palavra "x" aparece no texto "y" */
select t.nome, pt.ocorrencia from palavra_texto pt
inner join texto t
on t.idTex = pt.fk_text
inner join palavra p
on p.idPal = pt.fk_pal
where upper(t.nome) = upper('y') and upper(p.nome) = upper('x');

/* 17° - Quantas vezes a palavra "x" aparece em textos do tipo "y" */
select p.nome, tt.nome, sum(pt.ocorrencia) from texto t
inner join palavra_texto pt
on pt.fk_text = t.idTex
inner join tipo_texto tt
on tt.idTipText = t.fk_tipTex
inner join palavra p
on pt.fk_pal = p.idPal
where upper(tt.nome) = upper('y') and upper(p.nome) = upper('x')
group by p.nome, tt.nome;

/* 18º - Mostra textos e respectivos numero de palavras em cada*/
select t.nome, count(pt.idPalTex) from texto t
inner join palavra_texto pt
on pt.fk_text = t.idTex
group by t.nome;


/* 19° - Quantas vezes o autor "x" escreveu a palavra "y" */
select a.nome, sum(pt.ocorrencia), p.nome from texto t
inner join autor a
on a.idAut = t.fk_autor
inner join palavra_texto pt
on pt.fk_text = t.idTex
inner join palavra p
on p.idPal = pt.fk_pal
where upper(a.nome) = upper('Thomas Hobbes') and upper(p.nome) = upper('the')
group by a.nome, p.nome;

/* 20° - Mostre as palavras que seguem a palavra "x" */
select p1.nome Palavra_Atual, p2.nome Palavra_Prox from palavra_texto pt
inner join pal_tex_prox ptp
on ptp.fk_palTex = pt.idPalTex
inner join palavra p1
on p1.idPal = pt.fk_pal
inner join palavra p2
on p2.idPal = ptp.fk_pal
where upper(p1.nome) = upper('the');

--NÃO CONSEGUI FAZER
/* 21° - Mostre todos os autores e quantas palavras diferentes utilizaram*/
select a.nome Nome_Autor, count(p.idPal) from autor a
inner join texto t
on a.idAut = t.fk_autor
inner join palavra_texto pt
on pt.fk_text = t.idTex
inner join palavra p
on p.idPal = pt.fk_pal
group by a.nome;

/* 22º - Mostra as palavras e a palavra seguinte mais frequente*/
select p1.nome Palavra_Atual, p2.nome Palavra_Prox, ptp.ocorrencia from palavra_texto pt
inner join pal_tex_prox ptp
on ptp.fk_palTex = pt.idPalTex
inner join palavra p1
on p1.idPal = pt.fk_pal
inner join palavra p2
on p2.idPal = ptp.fk_pal;
