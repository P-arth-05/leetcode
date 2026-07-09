select e1.name as Employee
from Employee e1 join Employee e2
ON e2.id = e1.managerId
where e1.salary > e2.salary