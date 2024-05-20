# Write your MySQL query statement below
SELECT tem.player_id  AS player_id,
       tem.event_date AS first_login
FROM   (SELECT *,
               Row_number()
                 OVER(
                   partition BY player_id
                   ORDER BY event_date ASC) AS r
        FROM   activity) AS tem
WHERE  tem.r = 1 
