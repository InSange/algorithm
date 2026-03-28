# Write your MySQL query statement below
select p.firstName, p.lastName, a.city, if(a.state is null, Null, a.state) as state from person p left join address a on p.personid = a.personid