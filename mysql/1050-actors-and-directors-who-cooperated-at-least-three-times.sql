# Write your MySQL query statement below
SELECT actor_id,
       director_id
FROM   actordirector
GROUP  BY actor_id,
          director_id
HAVING 3 <= Count(timestamp)
