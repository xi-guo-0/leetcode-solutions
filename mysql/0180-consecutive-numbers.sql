SELECT
    DISTINCT l1.num AS consecutivenums
FROM
    logs AS l1, logs AS l2, logs AS l3
WHERE
    l1.id = l2.id - 1
    AND l2.id = l3.id - 1
    AND l1.num = l2.num
    AND l2.num = l3.num;
