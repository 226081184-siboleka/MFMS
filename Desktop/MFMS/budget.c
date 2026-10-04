#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "budget.h"

/* Parallel arrays: index i describes one department */
static char   deptNames[MAX_DEPARTMENTS][DEPT_NAME_LEN];
static double allocated[MAX_DEPARTMENTS];
static double expenditure[MAX_DEPARTMENTS];
static int    deptCount = 0;

/* ---------- Input helpers (validation) ---------- */

/* Reads a line safely; strips newline. Returns 0 on EOF. */
static int readLine(const char *prompt, char *buf, int size)
{
    printf("%s", prompt);
    if (fgets(buf, size, stdin) == NULL)
        return 0;
    buf[strcspn(buf, "\n")] = '\0';
    return 1;
}

/* Removes leading/trailing spaces in place */
static void trim(char *s)
{
    int start = 0;
    int len;

    while (s[start] != '\0' && isspace((unsigned char)s[start]))
        start++;
    if (start > 0)
        memmove(s, s + start, strlen(s + start) + 1);

    len = (int)strlen(s);
    while (len > 0 && isspace((unsigned char)s[len - 1])) {
        s[len - 1] = '\0';
        len--;
    }
}

/* Reads a non-empty department name */
static int readDeptName(const char *prompt, char *name)
{
    char buf[DEPT_NAME_LEN + 10];

    while (1) {
        if (!readLine(prompt, buf, sizeof buf))
            return 0;
        trim(buf);
        if (strlen(buf) == 0) {
            printf("  Error: name cannot be empty.\n");
        } else if (strlen(buf) >= DEPT_NAME_LEN) {
            printf("  Error: name too long (max %d characters).\n", DEPT_NAME_LEN - 1);
        } else {
            strcpy(name, buf);
            return 1;
        }
    }
}

/* Reads a valid number. If allowZero is 0, value must be > 0; else >= 0 */
static int readAmount(const char *prompt, double *value, int allowZero)
{
    char buf[64];
    char *end;
    double v;

    while (1) {
        if (!readLine(prompt, buf, sizeof buf))
            return 0;
        trim(buf);
        if (strlen(buf) == 0) {
            printf("  Error: please enter a number.\n");
            continue;
        }
        v = strtod(buf, &end);
        if (*end != '\0') {
            printf("  Error: '%s' is not a valid number.\n", buf);
        } else if (v < 0) {
            printf("  Error: negative amounts are not allowed.\n");
        } else if (v == 0 && !allowZero) {
            printf("  Error: amount must be greater than zero.\n");
        } else {
            *value = v;
            return 1;
        }
    }
}

/* Returns index of department, or -1 if not found */
static int findDepartment(const char *name)
{
    int i;
    for (i = 0; i < deptCount; i++) {
        if (strcmp(deptNames[i], name) == 0)
            return i;
    }
    return -1;
}

/* ---------- Calculations ---------- */

double calculateRemaining(double alloc, double spent)
{
    return alloc - spent;
}

int isWithinBudget(double alloc, double spent)
{
    return spent <= alloc;
}

/* ---------- Main budget operations ---------- */

void addDepartmentBudget(void)
{
    char name[DEPT_NAME_LEN];
    double amount;

    if (deptCount >= MAX_DEPARTMENTS) {
        printf("Department list is full (%d).\n", MAX_DEPARTMENTS);
        return;
    }
    if (!readDeptName("Department name: ", name))
        return;
    if (findDepartment(name) != -1) {
        printf("Department '%s' already exists.\n", name);
        return;
    }
    if (!readAmount("Allocated budget (N$): ", &amount, 0))
        return;

    strcpy(deptNames[deptCount], name);
    allocated[deptCount] = amount;
    expenditure[deptCount] = 0.0;
    deptCount++;
    printf("Budget for '%s' saved.\n", name);
}

void enterExpenditure(void)
{
    char name[DEPT_NAME_LEN];
    double amount;
    int idx;

    if (deptCount == 0) {
        printf("No departments yet. Add a department budget first.\n");
        return;
    }
    if (!readDeptName("Department name: ", name))
        return;
    idx = findDepartment(name);
    if (idx == -1) {
        printf("Department '%s' not found.\n", name);
        return;
    }
    if (!readAmount("Expenditure to add (N$): ", &amount, 1))
        return;

    expenditure[idx] += amount;
    printf("Recorded. Total spent: N$%.2f | Remaining: N$%.2f | Status: %s\n",
           expenditure[idx],
           calculateRemaining(allocated[idx], expenditure[idx]),
           isWithinBudget(allocated[idx], expenditure[idx]) ? "WITHIN BUDGET" : "OVER BUDGET");
}

void displayBudgets(void)
{
    int i;

    if (deptCount == 0) {
        printf("No budget data available.\n");
        return;
    }
    for (i = 0; i < deptCount; i++) {
        printf("\nDepartment: %s\n", deptNames[i]);
        printf("Allocated Budget: N$%.2f\n", allocated[i]);
        printf("Expenditure: N$%.2f\n", expenditure[i]);
        printf("Remaining Budget: N$%.2f\n", calculateRemaining(allocated[i], expenditure[i]));
        printf("Status: %s\n", isWithinBudget(allocated[i], expenditure[i]) ? "WITHIN BUDGET" : "OVER BUDGET");
    }
}

void displayExceededDepartments(void)
{
    int i, found = 0;

    printf("\nDepartments exceeding budget:\n");
    for (i = 0; i < deptCount; i++) {
        if (!isWithinBudget(allocated[i], expenditure[i])) {
            printf("  - %s (over by N$%.2f)\n", deptNames[i],
                   expenditure[i] - allocated[i]);
            found = 1;
        }
    }
    if (!found)
        printf("  None.\n");
}

/* ---------- Helpers for the Reports module ---------- */

int getDepartmentCount(void) { return deptCount; }

double getTotalAllocated(void)
{
    double total = 0.0;
    int i;
    for (i = 0; i < deptCount; i++)
        total += allocated[i];
    return total;
}

double getTotalExpenditure(void)
{
    double total = 0.0;
    int i;
    for (i = 0; i < deptCount; i++)
        total += expenditure[i];
    return total;
}

double getTotalRemaining(void)
{
    return calculateRemaining(getTotalAllocated(), getTotalExpenditure());
}

int countExceededDepartments(void)
{
    int i, count = 0;
    for (i = 0; i < deptCount; i++)
        if (!isWithinBudget(allocated[i], expenditure[i]))
            count++;
    return count;
}

void printBudgetReport(void)
{
    printf("\n===== BUDGET REPORT =====\n");
    printf("Total Allocated Budget: N$%.2f\n", getTotalAllocated());
    printf("Total Expenditure:      N$%.2f\n", getTotalExpenditure());
    printf("Remaining Budget:       N$%.2f\n", getTotalRemaining());
    displayExceededDepartments();
}

/* ---------- Menu ---------- */

void BudgetMenu(void)
{
    char buf[32];
    char *end;
    long choice;

    do {
        printf("\n========== BUDGET MANAGEMENT ==========\n");
        printf("1. Add department budget\n");
        printf("2. Enter expenditure\n");
        printf("3. Display budget information\n");
        printf("4. Show departments over budget\n");
        printf("5. Back to main menu\n");
        if (!readLine("Enter your choice: ", buf, sizeof buf))
            return;

        choice = strtol(buf, &end, 10);
        if (end == buf || *end != '\0')
            choice = -1;

        switch (choice) {
            case 1: addDepartmentBudget();       break;
            case 2: enterExpenditure();          break;
            case 3: displayBudgets();            break;
            case 4: displayExceededDepartments(); break;
            case 5: break;
            default: printf("Invalid choice. Enter 1-5.\n");
        }
    } while (choice != 5);
}
