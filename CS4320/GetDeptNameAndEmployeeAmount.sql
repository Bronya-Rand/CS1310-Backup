/*
  For each department, get the department name and
  the total number of employees whose saleries exceed 35000
  but only for departments where more than 3 employee works.
*/

SELECT Dname, count(*)
FROM Department JOIN Employee ON Dnumber = Dno
where Salary > 35000 AND Dno in (select Dno from Employee group by Dno having count(*) > 3)
Group by Dname
