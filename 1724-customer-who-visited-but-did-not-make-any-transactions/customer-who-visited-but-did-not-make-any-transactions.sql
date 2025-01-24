# Write your MySQL query statement below
select 
    v.customer_id as customer_id, 
    COUNT(v.customer_id) as count_no_trans from Visits as v
left outer join Transactions as t
on t.visit_id = v.visit_id
where t.visit_id is null
group by v.customer_id;