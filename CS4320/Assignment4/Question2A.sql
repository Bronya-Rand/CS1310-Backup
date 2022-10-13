select Fname, Lname
FROM Employee 
where Salary = (SELECT MAX(salary) from Employee)
group by Fname, Lname