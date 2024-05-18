SELECT
    firstname, lastname, city, state
FROM
    address
    RIGHT JOIN person ON person.personid = address.personid;
