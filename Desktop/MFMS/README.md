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
