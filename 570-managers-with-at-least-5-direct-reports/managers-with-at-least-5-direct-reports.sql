# Write your MySQL query statement below
select name from Employee
where id in (
    select distinct e.managerId from Employee as e
    group by e.managerId
    having count(e.managerId) >= 5
);


