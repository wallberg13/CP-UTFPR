/*
SET TERM ^;
	create PROCEDURE RetFunc(CodCli integer)
	RETURNS(NomeCli varchar(40))
	AS
	BEGIN
		select F.nomefunc from funcionario F where F.CODIGO = :CodCli
		INTO :NomeCli;
		EXIT;		
	END^
SET TERM ; ^

execute procedure RetFunc(3);

--ISSO NÃO EXECUTA POIS PRECISA EXIBIR MULTIPLAS LINHAS
SET TERM ^;
	create PROCEDURE RetFunc2(CodCli integer)
	RETURNS(NomeCli varchar(40))
	AS
	BEGIN
		select F.nomefunc from funcionario F
		INTO :NomeCli;
		EXIT;		
	END^
SET TERM ; ^ */

/* VARIAVEL LOCAL: DECLARE VARIABLE TESTE INTEGER*/

/* Faça uma SP que recebe um codigo e um nome de depto e os insere na tabela*/
/*
SET TERM ^;
    create procedure insereDpto(CodDpt integer, dpto varchar(40))
    as
    AREA PARA VARIAVEL LOCAL
    begin
        insert into departamento(ID, DEPTO) values (:CodDpt, :dpto);
        exit;
    end^
SET TERM ;^
commit; */

/* Exception
create exception teste 'Não existe';
commit; 

set term ^;
create PROCEDURE teste4(VarIn integer)
returns( varout varchar(20))
as
declare variable var integer;
begin
    var = :VarIn;
    select F.NOMEFUNC from FUNCIONARIO F where F.codigo = :var
    into :VarOut;
    
    if(:var > 10) then
    begin
    
    end
    else
end^
set term ;^ */

/*create exception ex1e 'Condição não atendida';
commit;
*/

set term ^;
create procedure ex1(x numeric(12,2))
returns (sMax numeric(12,2),iavg integer);
as
declare variable var numeric(12,2);
begin
    select max(f.salario), avg(f.idade) from funcionario f
    into :var, :iavg;
    
    if(var > :x) then
    begin
        sMax = :var;
    end
    else
        exception ex1e;
end^
set term ;^