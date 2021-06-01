create table parallelModeExp ( 
id serial primary key, 
date date not null,  
amount decimal(12,2)  not null 
); 

insert into parallelModeExp (date, amount) 
select current_date - (random() * 3650)::integer, (random() * 100000)::decimal(12,2) - 50000 
from generate_series(1,50000); 

explain analyze select sum(amount)  from parallelModeExp;

show max_parallel_workers_per_gather; 

set max_parallel_workers_per_gather to 4;

explain analyze select sum(amount)  from parallelModeExp;

create table tableToSort(
	id serial primary key,
	name varchar(20),
	amount decimal(12,2) not null
);
insert into tableToSort(name,amount) values('a',250);
insert into tableToSort(name,amount) values('b',200);
insert into tableToSort(name,amount) values('c',150);
insert into tableToSort(name,amount) values('d',50);

select * from tableToSort;

explain analyze select * from tableToSort order by name; 

set max_parallel_workers_per_gather to 4;

explain analyze select * from tableToSort order by name;