# Write your MySQL query statement below
SELECT s.NAME
FROM   orders o
       JOIN company c
         ON o.com_id = c.com_id
            AND c.NAME = 'RED'
       RIGHT JOIN salesperson s
               ON o.sales_id = s.sales_id
WHERE  o.sales_id IS NULL
