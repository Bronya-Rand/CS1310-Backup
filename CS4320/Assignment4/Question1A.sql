select Dname, count(*)
FROM Department JOIN Employee ON Dnumber = Dno
where Salary > 30000
group by Dname