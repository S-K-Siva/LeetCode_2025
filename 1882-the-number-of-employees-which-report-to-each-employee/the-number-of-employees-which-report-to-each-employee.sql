SELECT 
    emp.employee_id,
    emp.name,
    COUNT(emp1.employee_id) AS reports_count,
    ROUND(AVG(emp1.age)) AS average_age
FROM 
    employees AS emp
JOIN 
    employees AS emp1
    ON emp.employee_id = emp1.reports_to
GROUP BY 
    emp.employee_id, emp.name
ORDER BY 
    employee_id;