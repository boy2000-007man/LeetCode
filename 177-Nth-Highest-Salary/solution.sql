CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  declare N_1 int;
  set N_1 = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct Employee.Salary from Employee order by Employee.Salary desc limit N_1, 1
  );
END