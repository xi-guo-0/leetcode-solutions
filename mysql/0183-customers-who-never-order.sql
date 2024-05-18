SELECT
    c.name AS customers
FROM
    customers AS c
WHERE
    c.id NOT IN (SELECT customerid FROM orders);
