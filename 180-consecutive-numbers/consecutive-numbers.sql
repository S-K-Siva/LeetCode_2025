# Write your MySQL query statement below
select distinct t1.num as ConsecutiveNums
from logs t1, logs t2, logs t3
where t2.id = t1.id+1
and t3.id = t2.id+1
and t1.num = t2.num
and t2.num = t3.num;