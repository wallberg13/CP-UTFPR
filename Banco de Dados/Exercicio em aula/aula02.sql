/*Create Domain Dm_Chaveprimaria 
	Integer Not Null 
	Check (Value > 0); 

Create Domain Dm_Nome 
	Varchar(40) Not Null; 

Create Domain Dm_Fone 
	Varchar(20);


Create Domain Dm_Renda 
	Numeric (9,2) 
	Default 0 Not Null 
	Check (Value >= 0);

	
Create Domain Dm_sexo 
	char(1) not null
	check (value in ('M', 'F'));  	
	
Create Domain Dm_EstCivil as 
	char(1) 
	check (value in ('S', 'C', 'D', 'V', 'U')); 

	


Create Table Cliente(
    	PK_Cod 	DM_ChavePrimaria primary key,
		Nome 	DM_Nome,
    	Fone 	DM_Fone,
    	Fax 	DM_Fone,
		Renda 	DM_Renda,
    	Est_civil 	Dm_EstCivil,
    	Sexo 	Dm_sexo
); 



Create Table Funcionario(
   Codigo 	Integer Not Null Primary Key, 
   Nome 	Varchar(30) Not Null,
   Salario 	Numeric(12,2),
   Sexo 	char(1),
   Idade 	Integer,
   Uf 		char (2),
   Cidade 	varchar (40) not null,
   Est_Civil 	char (10));

INSERT INTO FUNCIONARIO 
	VALUES (1, 'Rodrigo Cardoso', 1588, 'm', 25, 'sc', 'Lages', 'Solteiro');

INSERT INTO FUNCIONARIO 
	VALUES (2, 'Maria Joaquina', 2000, 'f', 23, 'pr', 'Pato Branco', 'Casado');

INSERT INTO FUNCIONARIO 
	VALUES (4, 'Bastianzinho Silva', 1000, 'm', 55, 'pr', 'Curitiba', 'Casado');

INSERT INTO FUNCIONARIO 
	VALUES (3, 'Ana Paula', 4500, 'f', 34, 'sc', 'Florianopolis', 'Casado');

INSERT INTO FUNCIONARIO 
	VALUES (5, 'Tonico Alves', 1500, 'm', 25, 'sc', 'Sao Paulo', 'Solteiro');

INSERT INTO FUNCIONARIO 
	VALUES (6, 'Jose de Deus', 1000, 'm', 35, 'ba', 'Savador', 'Casado'); 


insert into funcionario values (7, 'Wallzito', 5000, 'M', 100, 'PI', 'Salvador', 'Na pista');

insert into funcionario values (7, 'Wallzito', 5000, 'M', 100, 'PI', 'Salvador', 'Na pista'); 

/* FUNÇÃO DE UPDATE 
    SINTAXE: UPDATE TABELA SET O_QUE_QUER_MUDAR WHERE RESULTADO_DE_QUEM_QUER_MUDAR


update funcionario set nome = 'Boa', est_civil = 'Na Farra', salario = 5000 where est_civil = 'Na Farra';
*/
 
/* FUNÇÃO DE DELETE 
    SINTAXE: DELETE FROM TABELA WHERE CONDIÇÃO;
             DELETE FROM TABELA; (CUIDADO, APAGA TODOS OS DADOS DA TABELA)

delete from funcionario where nome = 'Boa';
commit;
*/

/*
    SINTAXE BASICA DO select

select nome as nomefunc
from funcionario f 
where upper(f.nome) = upper('Wallzito');

select * from funcionario f
where idade between 25 and 35; */

/* Pesquisa por partes (LIKES) 
    %MARIA - TUDO QUE TERMINA COM MARIA
    MARIA% - TUDO QUE COMEÇA COM MARIA
    %MARIA% - TUDO QUE TEM O NOME MARIA NO MEIO
    __R % - TERCEIRO CARACTERE É R
    
    CONTRARIO O LIKE, POSSUI O "NOT LIKE",
    USA O MESMO ARGUMENTOS DO LIKE COM SENTIDO CONTRARIO.

select nome as nomefunc from funcionario f
where upper(f.nome) like upper('___l%');
*/
/* 
    FUNÇÕES ESPECIAIS
    MAX(),
    MIN(),
    AVG(),
    SUM(),
    COUNT()
*/
select count(*) as quantfunc from funcionario;
