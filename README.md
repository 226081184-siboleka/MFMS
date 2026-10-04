Student 226100480 Kemumuine Ngayozikue Kazondunge (STUDENT 1)

Overview
This module provides functionality to manage employee data within a municipal financial management system. It allows users to add, search, and display employee information, calculate salaries including allowances and tax, and generate summary reports.

Features
Add Employees: Register new employees with validation for unique IDs and non-empty names

Display Employees: View all registered employees in a formatted table

Search Employees: Find employees by ID or exact name

Salary Calculation: Calculate gross and net salaries with breakdowns

Employee Reports: Generate summary statistics including averages, highest, and lowest salaries

Project Structure
text
├── main.c          # Entry point and menu navigation
├── employees.c     # Employee management logic
├── employees.h     # Employee struct and function declarations
├── input.c         # Input validation utilities
├── input.h         # Input function declarations
└── README.md       # This file
Data Structure
Each employee record contains:

ID (unique identifier)

Name

Department

Email

Level

Basic Salary

Housing Allowance

Transport Allowance

Tax
Salary Calculation:
Gross Salary = Basic Salary + Housing Allowance + Transport Allowance;
Net Salary   = Gross Salary - Tax;


Input Validation
IDs: Must be unique and non-empty

Names: Cannot be empty

Numeric values: Must be non-negative numbers

Menu choices: Validated within acceptable ranges

Limits
Maximum employees: 100

Maximum ID length: 20 characters

Maximum name length: 60 characters

Maximum department length: 40 characters

Maximum email length: 60 characters

Maximum level length: 20 characters

*All monetary inputs and values will be saved in N$

How my functions work:
main() → employeeMenu(), displayEmployeeReport(), readIntInRange()

employeeMenu() → addEmployee(), displayEmployees(), searchEmployee(), calculateAndShowSalary(), displayEmployeeReport(), readIntInRange()

addEmployee() → readLine(), findEmployeeIndex(), readNonNegativeFloat(), calculateSalary()

displayEmployees() → calculateSalary()

searchEmployee() → readLine(), printEmployee()

calculateAndShowSalary() → readLine(), findEmployeeIndex(), calculateSalary()

printEmployee() → calculateSalary()

readLine(), readNonNegativeFloat(), readIntInRange() → standard library functions only
