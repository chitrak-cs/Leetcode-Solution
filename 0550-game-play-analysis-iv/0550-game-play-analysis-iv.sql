# Write your MySQL query statement below
SELECT
ROUND(COUNT(*)/
(SELECT COUNT(DISTINCT player_id) FROM Activity),2)
AS fraction
FROM Activity as a
JOIN(
    SELECT 
    player_id,
    MIN(event_date) AS first_date
    FROM Activity 
    GROUP BY player_id
) AS f
ON a.player_id = f.player_id
WHERE a.event_date = f.first_date + INTERVAL 1 DAY