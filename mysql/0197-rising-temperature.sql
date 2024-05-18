SELECT w1.id
FROM   weather AS w1,
       weather AS w2
WHERE  w1.temperature > w2.temperature
       AND Datediff(w1.recorddate, w2.recorddate) = 1; 
