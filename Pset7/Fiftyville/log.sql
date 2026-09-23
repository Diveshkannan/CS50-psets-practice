-- Keep a log of any SQL queries you execute as you solve the mystery.

--To find :
--          thief ?
--          city ?
--          accomplice ?

--data:
--          theft on 28 July,2025 at Humphrey Street

--info:
--          thief stole the CS50 duck and shortly took a flight out of town with help of accomplice

-- I start by checking the crime_scene_reports with the street name :Humphrey
SELECT * FROM crime_scene_reports WHERE street="Humphrey Street";
--query_info:
--          Theft took place at 10:15am at Humphrey Street Bakery with 3 witnesses and those 3 witnesses have given interviews .

-- I check the interviews given by 3 witnesses
SELECT * FROM interviews WHERE transcript LIKE "%bakery%";
--query_info:
--       Ruth said within 10mins of the theft, thief got into a car in the bakery parking lot and drove away.
--       Eugene saw the thief withdrawing money in the ATM on Leggett Street
--       Raymond heard thief talking to his accomplice when leaving the bakery , he heard thief want to take the earliest flight out of Fiftyville the next day and asked the person on the other end of the call to purchase a flight ticket.

-- I check the persons who did money withdrawal in the atm location in Leggett Street at the time frame
SELECT * FROM people JOIN bank_accounts ON people.id=bank_accounts.person_id WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_transactions WHERE year=2025 AND month=7 AND day=28 AND atm_location="Leggett Street" AND transaction_type="withdraw");
--query_info:
--      Got a list of person's details and the thief must be one of the them
--      Through this step my target(thief) in a field of whole city people whittled down to eight people

-- I check the bakery_security_logs
SELECT * FROM bakery_security_logs WHERE license_plate IN (SELECT people.license_plate FROM people JOIN bank_accounts ON people.id=bank_accounts.person_id WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_Transactions WHERE year=2025 AND day=28 AND month=7 AND atm_location="Leggett Street" AND transaction_type="withdraw") AND year=2025 AND day=28 AND month=7 AND hour=10 AND minute>15 AND activity="exit");
--query_info:
--      Through this step my target(thief) in a eight people whittled down to five people
--      Got a accurate list of members who drive away the car at the time frame and withdrawn money later in the same day

-- I check the 5 member's detail
SELECT * FROM people WHERE phone_number IN (SELECT phone_number FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE license_plate IN (SELECT people.license_plate FROM people JOIN bank_accounts ON people.id=bank_accounts.person_id WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_Transactions WHERE year=2025 AND day=28 AND month=7 AND atm_location="Leggett Street" AND transaction_type="withdraw")) AND year=2025 AND day=28 AND month=7 AND hour=10 AND minute>15 AND activity="exit"));
--query_info:
--      The prepatator must be one of the people ["Iman","Taylor","Luca","Diana","Bruce"]
--      Now I have their details

-- I check the phone calls
SELECT * FROM phone_calls where caller IN (SELECT phone_number FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE license_plate IN (SELECT people.license_plate FROM people JOIN bank_accounts ON people.id=bank_accounts.person_id WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_Transactions WHERE year=2025 AND day=28 AND month=7 AND atm_location="Leggett Street" AND transaction_type="withdraw")) AND year=2025 AND day=28 AND month=7 AND hour=10 AND minute>15 AND activity="exit")) AND year=2025 AND day=28 AND month=7 and duration<60;
--query_info:
--      Through this step my target(thief) in a five people whittled down to three people



-- I check phone calls with the people
SELECT * FROM people WHERE phone_number IN (SELECT caller FROM phone_calls where caller IN (SELECT phone_number FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE license_plate IN (SELECT people.license_plate FROM people JOIN bank_accounts ON people.id=bank_accounts.person_id WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_Transactions WHERE year=2025 AND day=28 AND month=7 AND atm_location="Leggett Street" AND transaction_type="withdraw")) AND year=2025 AND day=28 AND month=7 AND hour=10 AND minute>15 AND activity="exit")) AND year=2025 AND day=28 AND month=7 and duration<60);
--query_info:
--     The prepatator must be one of the people ["Taylor","Diana","Bruce"]
--     Filtered into 3 people
--     Now I have their details

-- I Check the flights and passengers on that time frame
SELECT * FROM passengers WHERE flight_id IN (SELECT flights.id FROM flights JOIN airports ON flights.origin_airport_id=airports.id WHERE airports.city="Fiftyville" AND flights.year=2025 and flights.day=29 and flights.month=7) AND passport_number IN (SELECT passport_number FROM people WHERE name in ("Taylor","Diana","Bruce"));
--query_info:
--      got info about 3 flights (id - (18,36,36))
--      got  passport_number of three members
--      got their seat number as well

-- I check the destination city
SELECT city FROM airports WHERE id IN (SELECT destination_airport_id FROM flights JOIN passengers ON flights.id=passengers.flight_id JOIN airports ON flights.origin_airport_id=airports.id WHERE airports.city="Fiftyville" and passengers.passport_number IN (SELECT passport_number FROM people WHERE name IN (SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls where caller IN (SELECT phone_number FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE license_plate IN (SELECT people.license_plate FROM people JOIN bank_accounts ON people.id=bank_accounts.person_id WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_Transactions WHERE year=2025 AND day=28 AND month=7 AND atm_location="Leggett Street" AND transaction_type="withdraw")) AND year=2025 AND day=28 AND month=7 AND hour=10 AND minute>15 AND activity="exit")) AND year=2025 AND day=28 AND month=7 and duration<60)))AND flights.year=2025 AND flights.month=7 AND flights.day=29);
--query_info:
--      The destination city must be one of the ("New York City","Boston")

-- I check cities id
SELECT id FROM airport WHERE city="New York City";
SELECT id FROM airport WHERE city="Boston";
SELECT id FROM airport WHERE city="Fiftyville";
--query_info"
--      NYC = 4
--      Boston = 6
--      Origin city id = 8

-- I check flights
SELECT city FROM airports WHERE id IN (SELECT destination_airport_id FROM flights WHERE origin_Airport_id=8 AND month=7 AND day=29 AND year=2025);
--query_info:
--       Flights from fiftyville on that day has gone to Chicago,New York City,Boston,Tokyo,San Francisco

-- I filter flights with passengers
SELECT city from airports WHERE id IN (SELECT destination_Airport_id FROM flights JOIN passengers ON flights.id=passengers.flight_id WHERE origin_Airport_id=8 AND month=7 and day=29 AND year=2025 AND passport_number IN (SELECT passport_number FROM people WHERE name IN ("Taylor","Bruce","Diana")))
--query_info:
--   Destinations are New York City and Boston

-- For Diana
SELECT city from airports WHERE id IN (SELECT destination_Airport_id FROM flights JOIN passengers ON flights.id=passengers.flight_id WHERE origin_Airport_id=8 AND month=7 and day=29 AND year=2025 AND passport_number IN (SELECT passport_number FROM people WHERE name IN ("Diana")))
--query_info:
--    Diana has taken flight to Boston
--    flight id = 18
--    seat = 4C
--    Time : 16:00 PM


-- For Taylor and Bruce
SELECT city from airports WHERE id IN (SELECT destination_Airport_id FROM flights JOIN passengers ON flights.id=passengers.flight_id WHERE origin_Airport_id=8 AND month=7 and day=29 AND year=2025 AND passport_number IN (SELECT passport_number FROM people WHERE name IN ("Diana")))
--query_info:
--    Taylor and Bruce have taken flight to New York City
--    flight id = 36
--    Taylor seat = 6D
--    Bruce seat = 4A
--    Time : 8:20 AM

-- Thief wanted to take the earliest flight out of town but Diana took the night flight . I exclude Diana from being as a Suspect .
-- Suspects - Taylor and Bruce
-- Escaped city - New York City
-- As both took the flight, I am going try finding by other tables

-- I check for the accomplice
SELECT name FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE caller IN (SELECT phone_number FROM people WHERE name IN("Taylor","Bruce")) AND month=7 AND year=2025 AND day=28 AND duration<60);
--query_info:
--       Suspects for accomplice are James,Robin


-- Taylor and Bruce both have taken their car out of bakery at that time frame
-- Taylor and Bruce both have taken the same flight
-- Taylor and Bruce both have spoken in call to others in less than 60 seconds on that day
-- Taylor, Diana and Bruce all have withdrawn money from ATM in leggett street

-- I check car out of bakery timing  ( as records it should be after 10mins of the theft )
SELECT * FROM bakery_security_logs WHERE year=2025 AND month=7 and day=28 and hour=10 AND activity="exit" AND license_plate IN(SELECT license_plate FROM people WHERE name IN ("Taylor","Bruce"));
--query_info:
--       Two cars was taken away
--       One of the two cars was taken out at 10:18 AM which was 3 minutes after theft , should be the thief's car
--       The other one was taken out after 20mins of the minutes which was after 10minutes and and should not be the thief's car

-- I check timings
SELECT * FROM bakery_security_logs WHERE year=2025 AND month=7 and day=28 and hour=10 AND activity="exit" AND license_plate IN(SELECT license_plate FROM people WHERE name IN ("Bruce"));
--query_info:
--      Car exits within 10mins
--      Bruce is the thief

SELECT * FROM bakery_security_logs WHERE year=2025 AND month=7 and day=28 and hour=10 AND activity="exit" AND license_plate IN(SELECT license_plate FROM people WHERE name ="Taylor");
--query_info:
--      This car exits after 10mins and Taylor is not thief


-- To find accomplice
SELECT name FROM people WHERE phone_number IN (SELECT receiver FROM phone_Calls WHERE caller = (SELECT phone_number FROM people WHERE name="Bruce") AND month=7 AND day=28 AND year=2025 AND duration<60);
--query_info:
--       Accomplice who spoke to Bruce at that time frame was Robin

-- Thief : Bruce
-- Escaped city : New York City
-- Accomplice: Robin

-- Mystery solved

-- CASE CLOSED---------





