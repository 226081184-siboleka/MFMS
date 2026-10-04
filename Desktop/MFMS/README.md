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

**Files created:** 'assets.c', 'assets.h', 'budget.c', 'budget.h', 'employees.c', 'employees.h', 'main.c', 'reports.c', 'reports.h', 'suppliers.c', and 'suppliers.h'

**Files edited:** 'main.c'

**main.c**
-Main navigation menu where users will choose which module to interact with.
