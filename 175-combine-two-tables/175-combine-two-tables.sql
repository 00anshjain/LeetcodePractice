# Write your MySQL query statement below
SELECT Person.firstName, Person.LastName, Address.City, Address.State from Person left join Address on
 Address.personID = person.personID;
