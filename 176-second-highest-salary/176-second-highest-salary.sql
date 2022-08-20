# Write your MySQL query statement below
# Without using limit
Select max(Salary) as SecondHighestSalary
from Employee
where salary not in (Select max(salary) from Employee);