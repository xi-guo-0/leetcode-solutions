# Write your MySQL query statement below
SELECT Round(Avg(a.event_date IS NOT NULL), 2) AS fraction
FROM   (SELECT player_id,
               Min(event_date) AS login
        FROM   activity
        GROUP  BY player_id) AS p
       LEFT JOIN activity AS a
              ON p.player_id = a.player_id
                 AND Datediff(a.event_date, p.login) = 1
