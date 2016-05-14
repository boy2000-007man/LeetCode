# Write your MySQL query statement below
(select distinct Salary from Employee order by Salary desc limit 1,1) union (select null) limit 0,1