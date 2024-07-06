SELECT s.product_id,
       s.year AS first_year,
       s.quantity,
       s.price
FROM   sales s
       JOIN (SELECT product_id,
                    Min(year) AS min_year
             FROM   sales
             GROUP  BY product_id) first_year_sales
         ON s.product_id = first_year_sales.product_id
            AND s.year = first_year_sales.min_year
ORDER  BY s.product_id;
