SELECT
    DISTINCT email AS email
FROM
    person
WHERE
    email
    IN (
            SELECT
                CASE WHEN count(id) > 1 THEN email END
            FROM
                person
            GROUP BY
                email
        );
