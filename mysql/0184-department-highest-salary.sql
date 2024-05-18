SELECT department.NAME AS 'Department',
       employee.NAME   AS 'Employee',
       salary
FROM   employee
       JOIN department
         ON employee.departmentid = department.id
WHERE  ( employee.departmentid, salary ) IN (SELECT departmentid,
                                                    Max(salary)
                                             FROM   employee
                                             GROUP  BY departmentid); 
