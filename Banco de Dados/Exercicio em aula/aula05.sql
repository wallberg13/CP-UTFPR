/** CREATE TABLE NFISCAL(
    COD INTEGER NOT NULL,
    PESSOA VARCHAR(20),
    VALOR NUMERIC(15,2),
    DATA DATE,
    primary key(COD)
);

commit; 

create generator codnf;

set term ^ ;
create trigger tNF_Cod FOR NFiscal
    active
        before insert
    as
    begin
        --NEW -> Estado do atributo que se quer mecher
        --gen_id(nome do gerador, incremento dele)
        NEW.COD = gen_id(codnf,1);
    end^
set term ; ^ 

insert into nfiscal(pessoa,valor) values ('WB',1000); */
/*
set term ^ ;
create trigger tNF_TestaValor FOR NFISCAL
    active
        before insert
    as
    begin
        --NEW -> Estado do atributo que se quer mecher
        --gen_id(nome do gerador, incremento dele)
        if(NEW.VALOR >= 1000) then
            NEW.VALOR = NEW.VALOR + 1.0;
    end^
set term ; ^ */

/*
insert into nfiscal(pessoa,valor) values ('WB',1002);
commit;

select * from nfiscal; */
