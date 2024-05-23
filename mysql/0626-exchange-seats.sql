# Write your MySQL query statement below
SELECT b.id,
       a.student
FROM   seat AS a,
       seat AS b,
       (
              SELECT Count(*) AS cnt
              FROM   seat) AS c
WHERE  b.id = 1^(a.id - 1) + 1
              || (c.cnt%2 && b.id=c.cnt && a.id=c.cnt);
