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

### Supplier Managament(student 3)
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
