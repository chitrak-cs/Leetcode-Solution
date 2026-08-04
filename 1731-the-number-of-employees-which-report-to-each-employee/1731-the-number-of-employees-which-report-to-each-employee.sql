# Write your MySQL query statement below
SELECT 
m.employee_id,
m.name,
COUNT(e.reports_to) AS reports_count,
ROUND(AVG(e.age),0) AS average_age
FROM Employees as e
RIGHT JOIN Employees as m
ON e.reports_to = m.employee_id
GROUP BY m.name,m.employee_id
HAVING reports_count > 0
ORDER BY employee_id 
