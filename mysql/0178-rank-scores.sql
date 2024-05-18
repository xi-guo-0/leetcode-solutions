SELECT
    a.score AS 'score',
    (
        SELECT
            count(DISTINCT b.score)
        FROM
            scores AS b
        WHERE
            b.score >= a.score
    )
        AS 'rank'
FROM
    scores AS a
ORDER BY
    a.score DESC;
