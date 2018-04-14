/* create domain pk integer not null check(value>0); */

create domain sexo char not null check(value in ('m','f')); 
create domain estcivil char not null check(value in('c','d','v','u','a','t')); 

/*
create table cliente(
    id pk primary key
); */