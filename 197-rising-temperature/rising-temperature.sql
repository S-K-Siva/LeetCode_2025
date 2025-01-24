# Write your MySQL query statement below
select w1.id as Id
from weather as w1
join weather as w2
on w1.recordDate = DATE_ADD(w2.recordDate,INTERVAL 1 DAY)
where w1.temperature > w2.temperature; 
