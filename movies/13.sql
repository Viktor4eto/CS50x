SELECT DISTINCT name FROM people JOIN (SELECT movies.id AS list FROM movies JOIN people, stars ON people.id = stars.person_id AND stars.movie_id = movies.id WHERE people.name = 'Kevin Bacon' AND people.birth = 1958), stars ON stars.person_id = people.id AND stars.movie_id = list;
