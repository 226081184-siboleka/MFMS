#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 20
#define DEPT_NAME_LEN   50

/* Menu and user-facing functions */
void BudgetMenu(void);
void addDepartmentBudget(void);
void enterExpenditure(void);
void displayBudgets(void);
void displayExceededDepartments(void);

/* Calculation functions (pass-by-value, return a result) */
double calculateRemaining(double allocated, double spent);
int    isWithinBudget(double allocated, double spent);

/* Helpers the Reports module can call */
int    getDepartmentCount(void);
double getTotalAllocated(void);
double getTotalExpenditure(void);
double getTotalRemaining(void);
int    countExceededDepartments(void);
void   printBudgetReport(void);

#endif
