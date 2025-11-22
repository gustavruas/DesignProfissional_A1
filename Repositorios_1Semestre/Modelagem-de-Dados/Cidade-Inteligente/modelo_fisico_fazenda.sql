create schema agronegocio;

create table agronegocio.categoria_cargo(
	id_cargo int primary key,
	nome varchar (100),
	salario decimal (10,3)
);

create table agronegocio.funcionario(
	cpf int primary key,
	nome varchar (100),
	rua varchar (100),
	email varchar (100),
	id_cargo int,
	
	FOREIGN KEY (id_cargo) REFERENCES agronegocio.categoria_cargo(id_cargo)
);


create table agronegocio.transporte(
	id_trans int primary key,
	tipo varchar(100)
);

create table agronegocio.locomove(
	id_trans int,
	cpf_funcionario int,

	PRIMARY KEY (id_trans, cpf_funcionario),

    FOREIGN KEY (id_trans) REFERENCES agronegocio.transporte(id_trans),
    FOREIGN KEY (cpf_funcionario) REFERENCES agronegocio.funcionario(cpf)
); 

create table agronegocio.fazenda(
	cfdf int primary key,
	rua varchar (100),
	cpf int,
	
	FOREIGN KEY (cpf) REFERENCES agronegocio.funcionario(cpf)
);

create table agronegocio.gado(
	cod_gado int primary key,
	raca varchar (100),
	data_nascimento date,
	cfdf int,
	
 FOREIGN KEY (cfdf) REFERENCES agronegocio.fazenda(cfdf)
);

create table agronegocio.compradores(
	cnpj CHAR(14) PRIMARY KEY,
    nome VARCHAR(120)
);

create table agronegocio.vende(
	nota_fiscal serial PRIMARY KEY,
    codigo_gado INT,
    cnpj_comprador CHAR(14) ,
    data_venda DATE,
    valor_venda NUMERIC(10,2),
	
	FOREIGN KEY (codigo_gado) REFERENCES gado(codigo),
	FOREIGN KEY (cnpj_comprador) REFERENCES compradores(cnpj)
);

create table agronegocio.racao(
	marca varchar (100),
	cfdf_fazenda int,
	quantidade int,
	validade date, 

	primary key (marca, cfdf_fazenda),
	FOREIGN KEY (cfdf_fazenda) REFERENCES fazenda(cfdf)

);

create table agronegocio.alimenta(
	codigo_gado int, 
	codigo int, 
	cfdf_fazenda int, 

	primary key (codigo_gado, codigo, cfdf_fazenda),
	
	foreign key (codigo_gado) references gado(codigo),
	foreign key (cfdf_fazenda ) references fazenda (cfdf)
);

create table agronegocio.vacina(
	id_vacina serial primary key, 
	nome varchar (100),
	lote varchar (100),
	validade date 
);

create table agronegocio.aplicacao_vacina(
	id_registro serial primary key, 
	data_aplicacao date,
	dose varchar (100),
	observacoes text, 
	id_vacina int, 
	cpf_funcionario varchar(100),

	foreign key (id_vacina) references vacina(id_vacina),
	foreign key (cpf_funcionario) references funcionario(cpf)
);

create table agronegocio.recebe(
	codigo_gado int,
	id_registro_aplicacao int,

	primary key (codigo_gado, id_registro_aplicacao),

	foreign key (codigo_gado) references gado(codigo),
	foreign key (id_registro_aplicacao) references aplicacao_vacina(id_registro)
);

insert into agronegocio.categoria_cargo (id_cargo,nome, salario) values 
(55, 'veterinario', 6.000 ), (56, 'peao', 4.000)

update agronegocio.categoria_cargo 
set salario = 4.900
where id_cargo = 56

select * from agronegocio.categoria_cargo;

delete from agronegocio.categoria_cargo 
where id_cargo = 55