SELECT a.firstName, a.lastName , b.city, b.state
FROM Person a LEFT JOIN Address b ON a.personId = b.personId