/** Seleciona todo mundo 
select f.nome, f.salario, f.uf 
from funcionario f */

/** Seleção ordenada/
select f.nome, f.salario, f.uf 
from funcionario f 
order by uf,salario */ 

/**
select avg(salario)
from funcionario f
order by 1 */

/* CONTANDO A QUANTIDADE POR ELEMENTOS:
EXEMPLO: CONTANDO QUANTO CAMPUS TEM DE CADA ESTADO NO BANCO.

select count(*), uf
from funcionario f 
group by uf*/

/*
    RESTRIGINDO A EXIBIÇÃO DO COUNT
    
select count(*), uf
from funcionario f
group by uf
having count(*) > 1 */

/*
select avg(idade), sexo
from funcionario f
group by sexo 
*/

/* MEDIA > 1000 E PERTENCER AOS ESTADOS DO SUL
select avg(salario),uf
from FUNCIONARIO f
where uf = 'sc' or uf = 'rs' or uf = 'pr'
group by uf
having avg(salario) > 1000 */

/* TIRA OS DUPLICADOS */
/* select distinct f.sexo from funcionario f */

/* MOSTRE OS DADOS PESSOAIS DO FUNCIONARIO QUE RECEBE O MAIOR SALARIO DE TODOS 
    COM ANINHAMENTO
    
   SELECT DENTRO DE CONDIÇÃO DE WHERE.
*/

select * from FUNCIONARIO f
where (salario = (select max(salario) from funcionario f))


