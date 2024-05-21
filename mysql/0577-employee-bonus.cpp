# Write your MySQL query statement below
SELECT name,
       bonus
FROM   employee
       LEFT JOIN bonus
              ON employee.empid = bonus.empid
WHERE  bonus IS NULL
        OR bonus < 1000; 
