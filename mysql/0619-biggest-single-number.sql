# Write your MySQL query statement below
SELECT Max(num) AS num
FROM  (SELECT num
       FROM   mynumbers
       GROUP  BY num
       HAVING Count(num) = 1) AS n;
