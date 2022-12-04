select name as Employee  
from Employee e
where salary > (select salary from Employee where id=e.managerId)