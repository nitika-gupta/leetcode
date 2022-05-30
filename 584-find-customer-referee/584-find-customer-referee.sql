# Write your MySQL query statement below
SELECT name from Customer 
WHERE  ISNULL(referee_id) OR referee_id<>2 ;