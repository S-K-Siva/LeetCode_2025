# Write your MySQL query statement below
select s.product_id,s.year as first_year,s.quantity,s.price
from sales s join (select product_id, min(year) as first_year from sales
group by product_id) as first_product
on s.product_id = first_product.product_id and s.year = first_product.first_year;