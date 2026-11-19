CREATE TABLE BRANCH (
    branch_name VARCHAR(50) PRIMARY KEY,
    branch_city VARCHAR(50),
    assets REAL
);

CREATE TABLE CUSTOMER (
    customer_name VARCHAR(50) PRIMARY KEY,
    customer_street VARCHAR(100),
    customer_city VARCHAR(50)
);

CREATE TABLE ACCOUNT (
    accno INT PRIMARY KEY,
    branch_name VARCHAR(50),
    balance REAL,
    FOREIGN KEY (branch_name) REFERENCES BRANCH(branch_name)
);

CREATE TABLE DEPOSITOR (
    customer_name VARCHAR(50),
    accno INT,
    PRIMARY KEY (customer_name, accno),
    FOREIGN KEY (customer_name) REFERENCES CUSTOMER(customer_name),
    FOREIGN KEY (accno) REFERENCES ACCOUNT(accno)
);

CREATE TABLE LOAN (
    loan_number INT PRIMARY KEY,
    branch_name VARCHAR(50),
    amount REAL,
    FOREIGN KEY (branch_name) REFERENCES BRANCH(branch_name)
);

CREATE TABLE BORROWER (
    customer_name VARCHAR(50),
    loan_number INT,
    PRIMARY KEY (customer_name, loan_number),
    FOREIGN KEY (customer_name) REFERENCES CUSTOMER(customer_name),
    FOREIGN KEY (loan_number) REFERENCES LOAN(loan_number)
);

INSERT INTO BRANCH VALUES
('Main', 'Delhi', 5000000),
('North', 'Delhi', 3000000),
('Civil Lines', 'Aligarh', 2500000),
('Mall Road', 'Lucknow', 4000000),
('Lake Road', 'Bhopal', 2000000);

INSERT INTO CUSTOMER VALUES
('Aman', 'Street 1', 'Delhi'),
('Bina', 'Street 2', 'Aligarh'),
('Chetan', 'Street 3', 'Lucknow'),
('Divya', 'Street 4', 'Bhopal'),
('Eshan', 'Street 5', 'Delhi');

INSERT INTO ACCOUNT VALUES
(101, 'Main', 10000),
(102, 'Main', 15000),
(103, 'North', 12000),
(104, 'Civil Lines', 9000),
(105, 'Mall Road', 11000);

INSERT INTO DEPOSITOR VALUES
('Aman', 101),
('Aman', 102),
('Bina', 103),
('Chetan', 104),
('Eshan', 105);

INSERT INTO LOAN VALUES
(201, 'Main', 50000),
(202, 'North', 60000),
(203, 'Civil Lines', 45000),
(204, 'Mall Road', 70000),
(205, 'Lake Road', 35000);

INSERT INTO BORROWER VALUES
('Aman', 201),
('Bina', 202),
('Chetan', 203),
('Divya', 204),
('Eshan', 205);

SELECT D.customer_name
FROM DEPOSITOR D
JOIN ACCOUNT A ON D.accno = A.accno
JOIN BRANCH B ON A.branch_name = B.branch_name
WHERE B.branch_name = 'Main'
GROUP BY D.customer_name
HAVING COUNT(DISTINCT D.accno) >= 2;

SELECT C.customer_name
FROM CUSTOMER C
WHERE NOT EXISTS (
    SELECT B.branch_name
    FROM BRANCH B
    WHERE B.branch_city = 'Delhi'
    AND NOT EXISTS (
        SELECT 1
        FROM DEPOSITOR D
        JOIN ACCOUNT A ON D.accno = A.accno
        WHERE D.customer_name = C.customer_name
        AND A.branch_name = B.branch_name
    )
);

DELETE FROM DEPOSITOR
WHERE accno IN (
    SELECT accno
    FROM ACCOUNT
    WHERE branch_name IN (
        SELECT branch_name
        FROM BRANCH
        WHERE branch_city = 'Delhi'
    )
);

DELETE FROM ACCOUNT
WHERE branch_name IN (
    SELECT branch_name
    FROM BRANCH
    WHERE branch_city = 'Delhi'
);
