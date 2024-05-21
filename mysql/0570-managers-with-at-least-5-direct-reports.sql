# Write your MySQL query statement below
SELECT a.name
FROM   employee AS a
       JOIN employee AS b
         ON a.id = b.managerid
GROUP  BY a.id
HAVING 5 <= Count(DISTINCT b.id) 
