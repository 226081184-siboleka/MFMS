/*
 * reports.c - Reports module (Student 5)
 *
 * Budget and Asset reports use functions from budget.c and assets.c.
 * The Employee and Supplier reports are placeholders until those two
 * modules are finished (see the notes inside each function).
 */

#include <stdio.h>
#include "reports.h"
#include "budget.h"
#include "assets.h"

#define LINE "========================================\n"

/* ---------- Small helper functions ---------- */

/* Prints a title between two lines */
static void printReportHeader(const char title[])
{
    printf("\n");
    printf(LINE);
    printf("  %s\n", title);
    printf(LINE);
}

/* Throws away leftover characters after scanf, up to the end of the line */
static void clearInput(void)
{
    int ch;

    ch = getchar();
    while (ch != '\n' && ch != EOF)
    {
        ch = getchar();
    }
}

/* ---------- Employee report (PLACEHOLDER) ---------- */

/*
 * TODO: replace this once employees.c exists. It needs to get from the
 * Employee module: the number of employees, and each employee's name,
 * ID and salary. Then loop through them to find the total, average,
 * highest and lowest salary.
 */
void employeeReport(void)
{
    printReportHeader("EMPLOYEE REPORT");
    printf("\nEmployee data is not connected yet.\n\n");
    printf(LINE);
}

/* ---------- Budget report ---------- */

void budgetReport(void)
{
    printReportHeader("BUDGET REPORT");

    /* Nothing stored: say so and stop */
    if (getDepartmentCount() == 0)
    {
        printf("\nNo budgets registered.\n\n");
        printf(LINE);
        return;
    }

    printf("\nDepartments: %d\n\n", getDepartmentCount());
    printf("Total Allocated Budget: N$%.2f\n", getTotalAllocated());
    printf("Total Expenditure:      N$%.2f\n", getTotalExpenditure());
    printf("Remaining Budget:       N$%.2f\n", getTotalRemaining());

    /* Prints the names of departments over budget, or "None." */
    displayExceededDepartments();

    printf("\n");
    printf(LINE);
}

/* ---------- Supplier report (PLACEHOLDER) ---------- */

/*
 * TODO: replace this once suppliers.c exists. It needs to get from the
 * Supplier module: the number of suppliers and each supplier's ID, name,
 * email, telephone and town, then print them in a loop.
 */
void supplierReport(void)
{
    printReportHeader("SUPPLIER REPORT");
    printf("\nSupplier data is not connected yet.\n\n");
    printf(LINE);
}

/* ---------- Asset report ---------- */

void assetReport(void)
{
    /* The Asset module prints its own header, table and totals,
       and also handles the "no assets" case. */
    displayAssetReport();
    printf("\n");
    printf(LINE);
}

/* ---------- Reports menu ---------- */

void displayReports(void)
{
    int choice = 0;
    int result;

    do
    {
        printf("\n");
        printf(LINE);
        printf("              REPORTS\n");
        printf(LINE);
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Return to Main Menu\n");
        printf(LINE);
        printf("Enter your choice: ");

        result = scanf("%d", &choice);
        if (result == EOF)
        {
            choice = 5;   /* input ended, so leave the menu */
        }
        else if (result != 1)
        {
            choice = 0;   /* the user typed letters, not a number */
        }
        if (result != EOF)
        {
            clearInput();
        }

        switch (choice)
        {
            case 1:
                employeeReport();
                break;
            case 2:
                budgetReport();
                break;
            case 3:
                supplierReport();
                break;
            case 4:
                assetReport();
                break;
            case 5:
                printf("\nReturning to main menu...\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number from 1 to 5.\n");
                break;
        }
    } while (choice != 5);
}
