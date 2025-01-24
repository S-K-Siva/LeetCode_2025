# Write your MySQL query statement below

-- using sub-query
-- select name from Employee
-- where id in (
--     select distinct e.managerId from Employee as e
--     group by e.managerId
--     having count(e.managerId) >= 5
-- );

select e.name 
from Employee as e
join (
    select managerId 
    from Employee
    group by managerId
    having count(managerId) >= 5
) e2 on e.id = e2.managerId;

