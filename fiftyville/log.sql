-- Keep a log of any SQL queries you execute as you solve the mystery.
.schema

SELECT * FROM crime_scene_reports;

.schema crime_scene_reports

SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28;

SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28;

SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10;

SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 ORDER BY minute;

SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10;

-- Relevant license plates
SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 30;

SELECT name, transcript  FROM interviews WHERE year = 2021 AND month = 7 AND day >= 28;

-- Relevant license plates after interviews
SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity =
'exit';

SELECT * FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

-- Table with callers and receivers around that time that lasted less than a minute (The caller is the theif and the receiver is the accomplice)
SELECT caller, receiver  FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

-- Gives the flight the theif wants to take
SELECT * FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1;

--Flight id
SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1;


-- CSF, Fiftyville Regional Airport, Fiftyville
SELECT * FROM airports JOIN flights ON flights.origin_airport_id = airports.id WHERE flights.id = (SELECT id FROM flights WHERE year = 20
21 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1);

-- Gives the city the thief escaped to: New York City (LGA - LaGuardia Airport)
SELECT * FROM airports JOIN flights ON flights.destination_airport_id = airports.id WHERE flights.id = (SELECT id FROM flights WHERE year
 = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1);