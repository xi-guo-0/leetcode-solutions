# Write your MySQL query statement below
WITH cte AS
(
         SELECT   customer_number,
                  Count(order_number) AS count1
         FROM     orders
         GROUP BY customer_number
         ORDER BY count1 DESC)
SELECT customer_number
FROM   cte limit 1
