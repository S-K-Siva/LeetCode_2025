select * from (SELECT u.name AS results
FROM movieRating AS mr
JOIN users AS u ON mr.user_id = u.user_id
GROUP BY u.name
HAVING COUNT(*) = (
    SELECT MAX(cnt)
    FROM (
        SELECT COUNT(*) AS cnt
        FROM movieRating
        GROUP BY user_id
    ) AS rating_counts
)
ORDER BY results
LIMIT 1
) as top_user

UNION ALL

select * from 
( SELECT m.title AS results
FROM movieRating AS mr
JOIN movies AS m ON mr.movie_id = m.movie_id
WHERE mr.created_at LIKE '2020-02-%'
GROUP BY m.movie_id
ORDER BY AVG(mr.rating) DESC, m.title
LIMIT 1
) as top_movie;
