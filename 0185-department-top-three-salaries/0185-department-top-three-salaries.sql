SELECT Department, Employee, Salary
FROM (
    SELECT 
        d.name AS Department,
        e.name AS Employee,
        e.salary AS Salary,
        DENSE_RANK() OVER (
            PARTITION BY d.id
            ORDER BY e.salary DESC
        ) AS rn
    FROM Employee e
    JOIN Department d
        ON e.departmentId = d.id
) x
WHERE rn <= 3;