# Write your MySQL query statement below
SELECT c.customer_id
FROM   customer AS c
       JOIN product AS p
         ON c.product_key = p.product_key
GROUP  BY c.customer_id
HAVING Count(DISTINCT c.product_key) >= (SELECT Count(*)
                                         FROM   product) 
