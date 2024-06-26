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

-- Gives a list of passport numbers that can belong to the thief
 SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY ho
ur LIMIT 1);

-- Gives 3 potential suspects: Sofia, Bruce and Kelsey
SELECT * FROM people JOIN (SELECT passport_number AS passport FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1)), (SELECT license_plate AS license FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = 'exit'), (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60) ON people.phone_number = caller AND people.passport_number = passport AND people.license_plate = license;

--Gives only the personal id
SELECT id FROM people JOIN (SELECT passport_number AS passport FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1)), (SELECT license_plate AS license FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = 'exit'), (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60) ON people.phone_number = caller AND people.passport_number = passport AND people.license_plate = license;

-- Gives all account numbers that withdrew money on that date
SELECT * FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

-- Gives the account numbers from the previous
SELECT account_number AS acc_num FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

-- Gives the person id of the account numbers from the previous statement
SELECT person_id FROM bank_accounts JOIN (SELECT account_number AS acc_num FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw') ON bank_accounts.account_number = acc_num;

-- Gives the person id of the theif
SELECT person_id FROM (SELECT person_id FROM bank_accounts JOIN (SELECT account_number AS acc_num FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw') ON bank_accounts.account_number = acc_num) JOIN (SELECT id FROM people JOIN (SELECT passport_number AS passport FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1)), (SELECT license_plate AS license FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = 'exit'), (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60) ON people.phone_number = caller AND people.passport_number = passport AND people.license_plate = license) ON person_id = id;

-- Reveals the theif: Bruce and all his info
SELECT * FROM people JOIN (SELECT person_id FROM (SELECT person_id FROM bank_accounts JOIN (SELECT account_number AS acc_num FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw') ON bank_accounts.account_number = acc_num) JOIN (SELECT id FROM people JOIN (SELECT passport_number AS passport FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1)), (SELECT license_plate AS license FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = 'exit'), (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60) ON people.phone_number = caller AND people.passport_number = passport AND people.license_plate = license) ON person_id = id) WHERE id = person_id;

-- Gives Bruce's phone number
SELECT phone_number FROM people JOIN (SELECT person_id FROM (SELECT person_id FROM bank_accounts JOIN (SELECT account_number AS acc_num FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw') ON bank_accounts.account_number = acc_num) JOIN (SELECT id FROM people JOIN (SELECT passport_number AS passport FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1)), (SELECT license_plate AS license FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = 'exit'), (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60) ON people.phone_number = caller AND people.passport_number = passport AND people.license_plate = license) ON person_id = id) WHERE id = person_id;

-- Gives the number of the receiver (aka accomplice)
SELECT receiver FROM (SELECT caller, receiver  FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60) JOIN (SELECT phone_number FROM people JOIN (SELECT person_id FROM (SELECT person_id FROM bank_accounts JOIN (SELECT account_number AS acc_num FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw') ON bank_accounts.account_number = acc_num) JOIN (SELECT id FROM people JOIN (SELECT passport_number AS passport FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1)), (SELECT license_plate AS license FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = 'exit'), (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60) ON people.phone_number = caller AND people.passport_number = passport AND people.license_plate = license) ON person_id = id) WHERE id = person_id) ON caller = phone_number;

-- Gives all info about the accomplice: Robin
SELECT * FROM people JOIN (SELECT receiver FROM (SELECT caller, receiver  FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60) JOIN (SELECT phone_number FROM people JOIN (SELECT person_id FROM (SELECT person_id FROM bank_accounts JOIN (SELECT account_number AS acc_num FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw') ON bank_accounts.account_number = acc_num) JOIN (SELECT id FROM people JOIN (SELECT passport_number AS passport FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1)), (SELECT license_plate AS license FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = 'exit'), (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60) ON people.phone_number = caller AND people.passport_number = passport AND people.license_plate = license) ON person_id = id) WHERE id = person_id) ON caller = phone_number) ON people.phone_number = receiver;
