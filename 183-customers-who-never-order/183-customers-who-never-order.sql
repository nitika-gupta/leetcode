# Write your MySQL query statement below
SELECT customers.name as 'Customers' from Customers 
WHERE customers.id NOT IN (SELECT customerID from Orders);