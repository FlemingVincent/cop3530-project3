# COP3530 Project 3
  Developed by Carter Johnson, Mira Menon, and Vincent Fleming

# Problem
  We would like to analyze and reduce search times in a randomly generated database which represents a large company consisting of 100,000 employees. Furthermore, we would only like employees to have access to general information about other employees such as first name, last name, and email. We would also like only company admins to have access to more personal employee information such as their SSN, address, username, and password.

# Motivation
  For large companies that support hundreds of thousands of employees, it is important to provide access to employee information in the most effective way possible, while also providing security of personal information. We believe the best way to do so is allowing employees to search for basic information about other employees, however, if an employee wants to see sensitive information their account must have access via username and password.

# Features
  The security feature assigns administrator status to ten employees, granting their assigned username and password access to an administrator search. When this option is selected, the user is prompted to enter a valid username and password, after four incorrect attempts, the program is terminated. If a correct username and password is entered, the user will have access to search for an employee’s more personal information such as ssn, username, and password.

# Data
  Our dataset was randomly generated using two python libraries: Faker and Pandas. Faker allowed us to call functions such as first_name(), last_name(), and ssn() to randomly generate values. In combination with Faker, Pandas was also used. Pandas allowed us to take the randomly generated data, store it in a dataframe, and then load that data into a .csv file. Our dataset follows the following schema: <br />
  EmployeeData(snn, first_name, last_name, address, email, username, passwordl) <br />
  AdminData(username, password)

# Tech Stack
  As stated earlier, our team decided to randomly generate data using a Python script which included two libraries: Faker and Pandas. In addition to Python, we also decided to use C++ to implement our data structures/algorithms. We figured this would be the safest option, considering we have been using C++ since COP3503, and if we were to run into any problems we could get help from TAs. For version control we decided that it would be best to implement Git, as this is how most projects are worked on in the software development industry.

# Distribution of Roles
  For this project, Carter Johnson was primarily in charge of data generation using Python, Pandas, and Faker. Vincent Fleming was primarily in charge of setting up, initializing, and maintaining version control using Git and GitHub. For data structure and algorithm implementation, Carter Johnson, Mira Menon, and Vincent Fleming all worked together.
