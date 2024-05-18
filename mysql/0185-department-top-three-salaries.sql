SELECT d.NAME  AS 'Department',
       e1.NAME AS 'Employee',
       e1.salary
FROM   employee e1
       JOIN department d
         ON e1.departmentid = d.id
WHERE  3 > (SELECT Count(DISTINCT e2.salary)
            FROM   employee e2
            WHERE  e2.salary > e1.salary
                   AND e1.departmentid = e2.departmentid); 
