CREATE TABLE PERSON (
    driver_id VARCHAR(20) PRIMARY KEY,
    name VARCHAR(50),
    address VARCHAR(100)
);

CREATE TABLE CAR (
    regno VARCHAR(20) PRIMARY KEY,
    model VARCHAR(50),
    year INT
);

CREATE TABLE ACCIDENT (
    report_number INT PRIMARY KEY,
    accd_date DATE,
    location VARCHAR(100)
);

CREATE TABLE OWNS (
    driver_id VARCHAR(20),
    regno VARCHAR(20),
    PRIMARY KEY (driver_id, regno),
    FOREIGN KEY (driver_id) REFERENCES PERSON(driver_id),
    FOREIGN KEY (regno) REFERENCES CAR(regno)
);

CREATE TABLE PARTICIPATED (
    driver_id VARCHAR(20),
    regno VARCHAR(20),
    report_number INT,
    damage_amount INT,
    PRIMARY KEY (driver_id, regno, report_number),
    FOREIGN KEY (driver_id) REFERENCES PERSON(driver_id),
    FOREIGN KEY (regno) REFERENCES CAR(regno),
    FOREIGN KEY (report_number) REFERENCES ACCIDENT(report_number)
);

INSERT INTO PERSON VALUES
('D1', 'Aman', 'Aligarh'),
('D2', 'Bina', 'Delhi'),
('D3', 'Chetan', 'Agra'),
('D4', 'Divya', 'Lucknow'),
('D5', 'Eshan', 'Noida');

INSERT INTO CAR VALUES
('ABC123', 'Honda City', 2020),
('DEF456', 'Swift', 2021),
('GHI789', 'Honda City', 2022),
('JKL012', 'i20', 2023),
('MNO345', 'City', 2024);

INSERT INTO ACCIDENT VALUES
(8, '2008-01-15', 'Aligarh'),
(9, '2008-03-20', 'Delhi'),
(10, '2008-06-10', 'Agra'),
(11, '2008-09-05', 'Lucknow'),
(12, '2008-12-25', 'Noida');

INSERT INTO OWNS VALUES
('D1', 'ABC123'),
('D2', 'DEF456'),
('D3', 'GHI789'),
('D4', 'JKL012'),
('D5', 'MNO345');

INSERT INTO PARTICIPATED VALUES
('D1', 'ABC123', 8, 10000),
('D2', 'DEF456', 9, 12000),
('D3', 'GHI789', 10, 15000),
('D4', 'JKL012', 11, 18000),
('D5', 'MNO345', 12, 20000);

UPDATE PARTICIPATED
SET damage_amount = 25000
WHERE regno = 'ABC123' AND report_number = 12;

INSERT INTO ACCIDENT VALUES (13, '2008-05-10', 'Aligarh');

SELECT COUNT(DISTINCT P.driver_id)
FROM PERSON P
JOIN OWNS O ON P.driver_id = O.driver_id
JOIN PARTICIPATED PT ON O.driver_id = PT.driver_id AND O.regno = PT.regno
JOIN ACCIDENT A ON PT.report_number = A.report_number
WHERE A.accd_date BETWEEN '2008-01-01' AND '2008-12-31';

SELECT COUNT(DISTINCT PT.report_number)
FROM PARTICIPATED PT
JOIN CAR C ON PT.regno = C.regno
WHERE C.model = 'Honda City';
