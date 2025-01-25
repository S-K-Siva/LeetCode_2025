# Write your MySQL query statement below
WITH TotalUsers AS (
    SELECT COUNT(DISTINCT user_id) AS total_users
    FROM Users
)
SELECT 
    r.contest_id, 
    ROUND(COUNT(DISTINCT r.user_id) * 100.0 / tu.total_users, 2) AS percentage
FROM Register AS r
CROSS JOIN TotalUsers AS tu
group by r.contest_id
order by percentage desc,
contest_id;