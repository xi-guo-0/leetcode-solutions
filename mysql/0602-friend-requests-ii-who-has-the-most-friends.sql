# Write your MySQL query statement below
SELECT id1        AS id,
       Count(id2) AS num
FROM   (SELECT requester_id AS id1,
               accepter_id  AS id2
        FROM   requestaccepted
        UNION ALL
        SELECT accepter_id  AS id1,
               requester_id AS id2
        FROM   requestaccepted) AS requests
GROUP  BY id1
ORDER  BY num DESC,
          id ASC
LIMIT  1;
