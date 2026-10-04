## Employee Management (student 1)
**Student details:** Kemumuine Ngayozikue Kazondunge, 226100480
**Files:** `employees.h` , `employees.c`, `inputs.h`,`inputs.c`

## Features
- **Add Employees** – unique ID, non-empty name, validated numeric inputs
- **Display Employees** – formatted table with ID, name, department, level, gross, net
- **Search Employees** – by ID or exact name
- **Salary Calculation** – gross = basic + housing + transport; net = gross − tax (tax ≤ gross)
- **Employee Report** – totals, averages, highest and lowest basic salaries
- **Input Validation** – safe reading of lines, non-negative floats, and ranged integers

 `addEmployee` : employees.c | Add a new employee with validation |
 `displayEmployees` : employees.c | Show all employees in a table |
 `searchEmployee` : employees.c | Find employee by ID or name |
 `calculateAndShowSalary` : employees.c | Show detailed salary breakdown |
 `displayEmployeeReport` : employees.c | Generate summary statistics |
 `findEmployeeIndex` : employees.c | Locate employee by ID |
 `calculateSalary` : employees.c | Compute gross and net salary |
 `printEmployee` (static) | employees.c | Print full details of one employee |
 `readLine` : input.c | Read a line of text safely |
 `readNonNegativeFloat` : input.c | Read a non-negative float |
 `readIntInRange` : input.c | Read an integer within a range |
`employeeMenu` (static) : main.c | Employee submenu loop |


## Budget Management (Student 2)
**student details:** Abel Thomas Mutji, 226095479
**Files:** `budget.c`, `budget.h`

**Features:**
- Enter departmental budgets
- Enter expenditure
- Calculate remaining budget
- Determine whether expenditure is within budget
- Display budget information
- Identify departments that have exceeded their allocated budget

**Main functions:**
`BudgetMenu()`, `addDepartmentBudget()`, `enterExpenditure()`, `displayBudgets()`, `displayExceededDepartments()`, `calculateRemaining()`, `isWithinBudget()`

**Reports support:**
- `getDepartmentCount()`
- `getTotalAllocated()`
- `getTotalExpenditure()`
- `getTotalRemaining()`
- `countExceededDepartments()`
- `printBudgetReport()`

## Supplier Managament(student 3)
**student details:** Sarafina Shilunga, 226106071
**files:** `suppliers.c``suppliers.h``test_suppliers.c`

***What it does***
- Add suppliers (ID, name, email, phone, town) with valdation
- Display all suppliers in a table
- Search by ID or by name (using strstr)
- Compare two suppliers using strcmp

***Functions***
-supplierMenu()
-addSupplier()
-displaySuppliers()
-compareSupplier
-getSupplierCount(), getSupplierID(), getSupplierName(), getSupplierExists() 

***Testing***
- 16 test case run via test_suppliers.c (All passing)


### Asset Management: [ Tomas K-O Sheefeni] ([ 226041069 ]  { --STUDENT 4-- } )

**Files:** `assets.c`, `assets.h`

**Features:**
- Add assets (ID, name, type, purchase value, department, condition)
- Display all assets in a table
- Search assets by ID, name, type or department
- Asset report with total count, total value and assets in poor condition

**Main functions:** `assetMenu()`, `addAsset()`, `displayAssets()`, `searchAsset()`, `displayAssetReport()`, `getAssetCount()`, `getTotalAssetValue()`

## Reports Module (Student 5)

**Files:** `reports.c`, `reports.h`

**Responsible student:** Kamwi Tjijandjeua Chizabulyo (225092433)

**Features:**
- Reports menu (Employee, Budget, Supplier, Asset) with invalid-choice handling
- Budget Report: total allocated budget, total expenditure, remaining budget, and the departments that exceeded their budget
- Asset Report: lists the registered assets with totals (uses the Asset module's report)
- Reports show a clear message when a module has no records
- Employee Report and Supplier Report: in progress, waiting for the Employee and Supplier modules

**How it works:** The Reports module keeps no data of its own. It reads totals and records from the other modules by calling their functions.


## Main menu, functions, validation and integration (Student 6)

**Student details:** Sarty Ndeshipanda Ndafyaalako, 226061248

**Files created:** `assets.c`, `assets.h`, `budget.c`, `budget.h`, `employees.c`, `employees.h`, `main.c`, `reports.c`, `reports.h`, `suppliers.c`, and `suppliers.h`

- In main.c; main navigation menu where users will choose which module to interact with.
- Header files edited so they are linked to main.c
- Function calls from '.c' files to header files
- Moved code from assets.c outside of main branch to assets.c in main branch, and ensure function calls match main.c.
- Moved code from assets.h outside of main branch to assets.h in main branch, and ensure function calls match main.c.
- Approved merge request to suppliers.c and suppliers.h in main branch
- Edited code in budget.c and budget.h to ensure it matches function call to main.c
- Attempts to edit code failed due to multiple errors in the file employees.c


##  Testing and documenting (Student 7)

**Student details:** simasiku siboleka 22608184

Testing and Documenting the codes 

Modular structure. The program is split into one source/header pair per module (employees, budget, suppliers, assets, reports), with main.c containing only the menu loop and calls to module functions. This avoids one large main() function.
Data storage. Records are held in arrays (e.g. parallel arrays or arrays of fixed-size character strings) with a counter for the number of records stored.
Control flow. main() displays the menu in a loop and uses a switch statement to call the relevant module function. Each module has its own sub-menu.
Key algorithms. - Search: loops through the stored records and compares the search key with strcmp(). - Salary: calculateSalary() receives basic salary and allowances as parameters and returns the total. - Budget: calculateBudget() returns allocated minus expenditure; an if/else determines the status. - Reports: loops compute totals, average, highest and lowest values.
String handling. strlen() is used to detect empty input, strcmp() for searching and matching, strcpy() for storing names, and strcat() for building display text where appropriate.
Validation. Dedicated helper functions read and check integer and decimal input, reject negative values, and re-prompt until valid.

