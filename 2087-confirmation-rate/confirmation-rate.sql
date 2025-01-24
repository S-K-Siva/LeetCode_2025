# Write your MySQL query statement below

select s.user_id, COALESCE(round(avg(CASE WHEN c.action="confirmed" THEN 1 ELSE 0 END),2),0.00) as confirmation_rate 
from Signups as s
left join confirmations as c
on c.user_id = s.user_id
group by user_id;
