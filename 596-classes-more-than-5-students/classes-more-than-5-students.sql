# Write your MySQL query statement below
-- select distinct class from courses c1
-- where (select count(*) as cnt from courses c2 where c2.class = c1.class) >= 5;

select class from courses
group by class having count(class) >= 5;