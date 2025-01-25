WITH first_logins AS (
    SELECT player_id, MIN(event_date) AS first_login_date
    FROM Activity
    GROUP BY player_id
),
next_day_logins AS (
    SELECT a.player_id
    FROM Activity AS a
    JOIN first_logins AS fl 
        ON a.player_id = fl.player_id
    WHERE a.event_date = DATE_ADD(fl.first_login_date, INTERVAL 1 DAY)
)
SELECT 
    ROUND(COUNT(DISTINCT ndl.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM 
    next_day_logins AS ndl;