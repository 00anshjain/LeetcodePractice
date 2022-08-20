# Write your MySQL query statement below
# Without using limit
Select(Select distinct salary
FROM Employee
order by Salary Desc
Limit 1, 1) AS SecondHighestSalary;