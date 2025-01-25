# Write your MySQL query statement below

-- with getCount as (
--     select country,left(trans_date,7) as date_month,nullif(count(month(trans_date)),0) as count_trans_date
--     from Transactions
--     group by left(trans_date,7),country
-- ),
-- getApprovedCount as (
--     select country,left(trans_date,7) as date_month,nullif(count(month(trans_date)),0) as count_approved_trans_date
--     from Transactions
--     where state = 'approved'
--     group by left(trans_date,7),country
-- ),
-- getTransTotalAmount as (
--     select country,left(trans_date,7) as date_month, nullif(sum(amount),0) as trans_total_amount
--     from Transactions
--     group by left(trans_date,7),country
-- ),
-- getTransApprovedTotalAmount as (
--     select country,left(trans_date,7) as date_month, nullif(sum(amount),0) as trans_total_amount
--     from Transactions
--     where state = 'approved'
--     group by left(trans_date,7),country
-- )
-- select gc.date_month as month, gc.country,
-- coalesce((gc.count_trans_date),0) as trans_count,
-- coalesce((gac.count_approved_trans_date),0) as approved_count,
-- coalesce((gta.trans_total_amount),0) as trans_total_amount,
-- coalesce((gtata.trans_total_amount),0) as approved_total_amount
-- from getCount as gc
-- left join getApprovedCount as gac
-- on gac.date_month = gc.date_month
-- and gac.country = gc.country or (gac.country is null and gc.country is null)
-- left join getTransTotalAmount as gta
-- on gta.date_month = gc.date_month 
-- and gta.country = gc.country or (gta.country is null and gc.country is null)
-- left join getTransApprovedTotalAmount as gtata
-- on gtata.date_month = gc.date_month
-- and gtata.country = gc.country or (gtata.country is null and gc.country is null)
-- order by gc.date_month, gc.country;

-- combining all cte...
WITH aggregatedData AS (
    SELECT 
        LEFT(trans_date, 7) AS date_month,
        country,
        COUNT(*) AS trans_count,
        SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
        SUM(amount) AS trans_total_amount,
        SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount
    FROM Transactions
    GROUP BY LEFT(trans_date, 7), country
)
SELECT 
    date_month AS month,
    country,
    trans_count,
    approved_count,
    trans_total_amount,
    approved_total_amount
FROM aggregatedData
ORDER BY date_month, country;