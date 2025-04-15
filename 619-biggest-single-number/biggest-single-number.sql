# Write your MySQL query statement below
select max(nm.num) as num from mynumbers as nm
join( 
select count(*) as cnt, max(num) as num from mynumbers
group by num having cnt = 1
) as numbers where nm.num = numbers.num;
