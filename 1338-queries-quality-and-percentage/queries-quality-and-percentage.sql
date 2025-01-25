# Write your MySQL query statement below
with query_name_count as (
    select query_name ,count(*) as total_queries from Queries
    group by query_name
),
poor_queries_table as (
    select query_name , COUNT(*) as poor_queries from Queries
    where rating < 3
    group by query_name
)
select main.query_name,
    coalesce(round(sum(main.rating * 1.0 / main.position * 1.0)/qnc.total_queries,2),0.00) as quality, 
    coalesce(round((coalesce(pqt.poor_queries,0)/coalesce(qnc.total_queries,0)* 100),2),0.00) as poor_query_percentage
from Queries as main
join query_name_count as qnc
on qnc.query_name = main.query_name
left join poor_queries_table as pqt
on pqt.query_name = main.query_name
group by main.query_name
order by main.query_name;

