# Write your MySQL query statement below
select e.name, b.bonus from Employee as e
left outer join bonus as b
on e.empId = b.empId
where b.bonus < 1000
or b.empId is null;