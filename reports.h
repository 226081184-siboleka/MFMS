#ifndef REPORTS_H
#define REPORTS_H

/*
 * reports.h - Reports module (Student 5)
 *
 * The Reports module does not keep any data of its own. It asks the
 * other modules (budget, assets, employees, suppliers) for their
 * totals and records by calling their functions.
 */

/* Shows the Reports menu. main.c calls this for "5. Reports". */
void displayReports(void);

/* The four individual reports */
void employeeReport(void);
void budgetReport(void);
void supplierReport(void);
void assetReport(void);

#endif
