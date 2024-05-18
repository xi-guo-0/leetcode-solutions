SELECT T.request_at                                                      AS
       `Day`,
       Round(Sum(IF(T.status = 'completed', 0, 1)) / Count(T.status), 2) AS
       `Cancellation Rate`
FROM   trips AS T
       JOIN users AS U1
         ON ( T.client_id = U1.users_id
              AND U1.banned = 'No' )
       JOIN users AS U2
         ON ( T.driver_id = U2.users_id
              AND U2.banned = 'No' )
WHERE  T.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP  BY T.request_at 
