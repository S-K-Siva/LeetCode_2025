# Write your MySQL query statement below
select p.product_id, COALESCE(round(
    sum(case
            when u.purchase_date between p.start_date and p.end_date 
            then p.price * u.units
            else 0
            end
    )/coalesce(sum(case
            when u.purchase_date between p.start_date and p.end_date 
            then u.units
            else 0
            end
    ),0),2),0) as average_price
from Prices as p
left join UnitsSold as u
on p.product_Id = u.product_id
group by product_id
order by product_id;