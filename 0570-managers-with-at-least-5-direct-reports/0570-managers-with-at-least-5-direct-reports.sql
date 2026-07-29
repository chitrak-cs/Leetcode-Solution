# Write your MySQL query statement below
SELECT 
COALESCE(e2.name,NULL) as name
FROM Employee as e1
JOIN Employee as e2
ON e1.managerId = e2.id
GROUP BY e2.id
HAVING COUNT(*) >= 5
