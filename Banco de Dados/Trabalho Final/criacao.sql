create table autor(
	idAut integer not null primary key auto_increment,
	nome varchar(100) not null unique
);

commit;

create table tipo_texto(
	idTipText integer not null primary key auto_increment,
	nome varchar(100) not null unique
);

commit;

create table idioma(
	idIdioma integer not null primary key auto_increment,
	nome varchar(100) not null unique
);

commit;

create table palavra(
	idPal integer not null primary key auto_increment,
	nome varchar(100) not null,
	fk_idioma integer not null,
	constraint const_fk_ido foreign key (fk_idioma) references idioma(idIdioma)
);

commit;

create table texto(
	idTex integer not null primary key auto_increment,
	nome varchar(100) not null unique,
	fk_tipTex integer not null,
	fk_autor integer not null,
	fk_idioma integer not null,
	constraint const_fk_tipTex foreign key (fk_tipTex) references tipo_texto(idTipText),
	constraint const_fk_autor foreign key (fk_autor) references autor(idAut),
	constraint const_fk_idioma foreign key (fk_idioma) references idioma(idIdioma)
);

commit;

create table palavra_texto(
	idPalTex integer not null primary key auto_increment,
	fk_text integer not null,
	fk_pal integer not null,
	ocorrencia integer default 1,
	constraint const_fk_text_pt foreign key (fk_text) references texto(idTex),
	constraint const_fk_pal_pt foreign key (fk_pal) references palavra(idPal)
);

commit;

create table pal_tex_prox(
	idPalTexProx integer not null primary key auto_increment,
	fk_palTex integer not null,
	fk_pal integer not null,
	ocorrencia integer default 1,
	constraint const_fk_palTex foreign key (fk_palTex) references palavra_texto(idPalTex),
	constraint const_fk_pal_ptp foreign key (fk_pal) references palavra(idPal)
);
