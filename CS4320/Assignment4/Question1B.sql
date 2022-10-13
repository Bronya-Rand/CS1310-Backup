select Dname, count(*)
FROM Department JOIN Employee ON Dnumber = Dno
where Salary > 30000 AND Sex in (select Sex from Employee group by Sex HAVINGSex = 'M')
group by Dname