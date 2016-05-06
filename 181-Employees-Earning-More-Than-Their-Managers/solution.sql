# Write your MySQL query statement below
select a.Name from Employee a join Employee b on a.ManagerId=b.Id where a.Salary>b.Salary