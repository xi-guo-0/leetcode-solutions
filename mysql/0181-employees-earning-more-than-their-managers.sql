SELECT
    name AS employee
FROM
    employee AS a
WHERE
    a.salary
    > (
            SELECT
                b.salary
            FROM
                employee AS b
            WHERE
                a.managerid = b.id
        );
