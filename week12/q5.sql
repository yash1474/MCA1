CREATE TABLE University (
    university_id INT PRIMARY KEY,
    university_name VARCHAR(100),
    location VARCHAR(100),
    establishment_year INT
);

CREATE TABLE Department (
    department_id INT PRIMARY KEY,
    department_name VARCHAR(100),
    university_id INT,
    location VARCHAR(100),
    FOREIGN KEY (university_id) REFERENCES University(university_id)
);

CREATE TABLE Program (
    program_id INT PRIMARY KEY,
    program_name VARCHAR(100),
    university_id INT,
    duration INT,
    FOREIGN KEY (university_id) REFERENCES University(university_id)
);

CREATE TABLE Course (
    course_id INT PRIMARY KEY,
    course_name VARCHAR(100),
    program_id INT,
    credits INT,
    FOREIGN KEY (program_id) REFERENCES Program(program_id)
);

CREATE TABLE Syllabus (
    syllabus_id INT PRIMARY KEY,
    course_id INT,
    university_id INT,
    content TEXT,
    FOREIGN KEY (course_id) REFERENCES Course(course_id),
    FOREIGN KEY (university_id) REFERENCES University(university_id)
);

CREATE TABLE Faculty (
    faculty_id INT PRIMARY KEY,
    faculty_name VARCHAR(100),
    university_id INT,
    specialization VARCHAR(100),
    FOREIGN KEY (university_id) REFERENCES University(university_id)
);

CREATE INDEX idx_university_location ON University(location);
CREATE INDEX idx_department_name ON Department(department_name);
CREATE INDEX idx_program_name ON Program(program_name);
CREATE INDEX idx_course_name ON Course(course_name);
CREATE INDEX idx_syllabus_course ON Syllabus(course_id);
CREATE INDEX idx_faculty_specialization ON Faculty(specialization);

INSERT INTO University VALUES
(1, 'AMU', 'Aligarh', 1920),
(2, 'JNU', 'Delhi', 1969),
(3, 'University of Jammu', 'Jammu', 1969),
(4, 'DU', 'Delhi', 1922),
(5, 'BHU', 'Varanasi', 1916);

INSERT INTO Department VALUES
(1, 'Computer Science', 1, 'Aligarh'),
(2, 'Computer Science', 2, 'Delhi'),
(3, 'Computer Science', 3, 'Jammu'),
(4, 'Mathematics', 4, 'Delhi'),
(5, 'Information Technology', 5, 'Varanasi');

INSERT INTO Program VALUES
(1, 'MCA', 1, 2),
(2, 'MCA', 2, 2),
(3, 'MCA', 3, 2),
(4, 'BCA', 4, 3),
(5, 'MSc IT', 5, 2);

INSERT INTO Course VALUES
(1, 'Computer Architecture', 1, 4),
(2, 'Database Systems', 2, 4),
(3, 'Computer Architecture', 3, 4),
(4, 'Programming', 4, 3),
(5, 'Networks', 5, 4);

INSERT INTO Syllabus VALUES
(1, 1, 1, 'Computer Architecture syllabus'),
(2, 2, 2, 'Database Systems syllabus'),
(3, 3, 3, 'Computer Architecture syllabus'),
(4, 4, 4, 'Programming syllabus'),
(5, 5, 5, 'Networks syllabus');

INSERT INTO Faculty VALUES
(1, 'Ali', 1, 'Information Security'),
(2, 'Bina', 2, 'Database Systems'),
(3, 'Chetan', 3, 'Information Security'),
(4, 'Divya', 4, 'Mathematics'),
(5, 'Eshan', 5, 'Networks');

SELECT * FROM University WHERE location = 'Delhi';
SELECT D.department_name FROM Department D JOIN University U ON D.university_id = U.university_id WHERE U.university_name = 'AMU';
SELECT location FROM University WHERE university_name = 'JNU';
SELECT P.program_name FROM Program P JOIN University U ON P.university_id = U.university_id WHERE U.university_name = 'University of Jammu';
SELECT U.university_name FROM University U JOIN Program P ON U.university_id = P.university_id WHERE P.program_name = 'MCA';
SELECT C.course_name FROM Course C JOIN Program P ON C.program_id = P.program_id JOIN University U ON P.university_id = U.university_id WHERE P.program_name = 'MCA' AND U.university_name = 'AMU';
SELECT faculty_name, university_id FROM Faculty WHERE specialization = 'Information Security';
SELECT S.syllabus_id, S.content FROM Syllabus S JOIN Course C ON S.course_id = C.course_id JOIN University U ON S.university_id = U.university_id WHERE C.course_name = 'Computer Architecture';
