# Write your MySQL query statement below
SELECT name
FROM   customer
WHERE  id NOT IN (SELECT id
                  FROM   customer
                  WHERE  referee_id = 2) 
