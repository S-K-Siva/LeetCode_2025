# Write your MySQL query statement below
select x,y,z,"Yes" as triangle from triangle
where x+y > z and y+z > x and z+x > y
union
select x,y,z,"No" as triangle from triangle
where not (x+y > z and y+z > x and z+x > y);