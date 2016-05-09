# Write your MySQL query statement below
select Email from (select count(Id) as cnt, Email from Person group by Email) a where cnt>1