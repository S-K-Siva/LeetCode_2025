# Write your MySQL query statement below

-- select tweet_id from Tweets 
-- where LENGTH(content) > 15;

-- another way
select tweet_id from Tweets
where char_length(content) > 15;