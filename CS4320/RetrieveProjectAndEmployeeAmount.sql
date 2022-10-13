/*
  For each project, retrieve the project number, the project name
  and the number of employees from department 5 who work on the project.
*/

select pnumber, pname, count(*)
from PROJECT JOIN Works_ON ON Pnumber = Pno
             JOIN Employee ON SSN = ESSN
where Dno = 5
group by pnumber, pname