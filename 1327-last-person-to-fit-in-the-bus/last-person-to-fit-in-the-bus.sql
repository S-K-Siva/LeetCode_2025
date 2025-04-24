# Write your MySQL query statement below


select sub.person_name from (
select q1.person_id,q1.person_name, q1.turn, (
    select sum(q.weight) from queue as q
    where q.turn <= q1.turn
) as total_weight
from queue as q1
) as sub
where sub.total_weight <= 1000
order by sub.total_weight desc
limit 1
