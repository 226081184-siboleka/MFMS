#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "input.h"

/* ---------- Forward declarations (internal helpers) ---------- */
static void printEmployee(const Employee *e);

/* ---------- Salary calculation ---------- */
void calculateSalary(const Employee *e, float *gross, float *net)
{
    *gross = e->basicSalary + e->housingAllowance + e->transportAllowance;
    *net   = *gross - e->tax;
}

/* ---------- Lookup ---------- */
int findEmployeeIndex(const Employee employees[], int count, const char *id)
{
    for (int i = 0; i < count; i++)
        if (strcmp(employees[i].id, id) == 0)
            return i;
    return -1;
}

/* ---------- Print one employee (helper) ---------- */
static void printEmployee(const Employee *e)
{
    float gross, net;
    calculateSalary(e, &gross, &net);

    printf("  ID         : %s\n",     e->id);
    printf("  Name       : %s\n",     e->name);
    printf("  Department : %s\n",     e->department);
    printf("  Email      : %s\n",     e->email);
    printf("  Level      : %s\n",     e->level);
    printf("  Basic      : N$%.2f\n", e->basicSalary);
    printf("  Housing    : N$%.2f\n", e->housingAllowance);
    printf("  Transport  : N$%.2f\n", e->transportAllowance);
    printf("  Gross      : N$%.2f\n", gross);
    printf("  Tax        : N$%.2f\n", e->tax);
    printf("  Net salary : N$%.2f\n", net);
}

/* ---------- Add ---------- */
void addEmployee(Employee employees[], int *count)
{
    if (*count >= MAX_EMPLOYEES) {
        printf("\n  ! Employee list is full.\n");
        return;
    }

    Employee e;

    /* ID: non-empty and unique */
    for (;;) {
        readLine("Enter employee ID: ", e.id, sizeof e.id);
        if (strlen(e.id) == 0)
            printf("  ! ID cannot be empty.\n");
        else if (findEmployeeIndex(employees, *count, e.id) != -1)
            printf("  ! ID %s already exists.\n", e.id);
        else
            break;
    }

    /* Name: non-empty */
    do {
        readLine("Enter employee name: ", e.name, sizeof e.name);
        if (strlen(e.name) == 0)
            printf("  ! Name cannot be empty.\n");
    } while (strlen(e.name) == 0);

    readLine("Enter department: ", e.department, sizeof e.department);
    readLine("Enter email     : ", e.email,      sizeof e.email);
    readLine("Enter level     : ", e.level,      sizeof e.level);

    e.basicSalary        = readNonNegativeFloat("Enter basic salary (N$)       : ");
    e.housingAllowance   = readNonNegativeFloat("Enter housing allowance (N$)  : ");
    e.transportAllowance = readNonNegativeFloat("Enter transport allowance (N$): ");

    float gross, net;
    for (;;) {
        e.tax = readNonNegativeFloat("Enter tax (N$)                : ");
        calculateSalary(&e, &gross, &net);
        if (net < 0)
            printf("  ! Tax cannot exceed gross salary (N$%.2f).\n", gross);
        else
            break;
    }

    employees[*count] = e;
    (*count)++;

    printf("\nEmployee \"%s\" added. Net salary: N$%.2f\n", e.name, net);
}

/* ---------- Display all ---------- */
void displayEmployees(const Employee employees[], int count)
{
    if (count == 0) {
        printf("\nNo employees registered yet.\n");
        return;
    }

    printf("\n%-10s %-22s %-16s %-12s %12s %12s\n",
           "ID", "Name", "Department", "Level", "Gross", "Net");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        float gross, net;
        calculateSalary(&employees[i], &gross, &net);
        printf("%-10s %-22s %-16s %-12s %12.2f %12.2f\n",
               employees[i].id, employees[i].name, employees[i].department,
               employees[i].level, gross, net);
    }
    printf("\nTotal employees: %d\n", count);
}

/* ---------- Search ---------- */
void searchEmployee(const Employee employees[], int count)
{
    if (count == 0) {
        printf("\nNo employees registered yet.\n");
        return;
    }

    char key[MAX_NAME_LEN];
    readLine("Enter employee ID or exact name: ", key, sizeof key);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].id, key) == 0 ||
            strcmp(employees[i].name, key) == 0) {
            printf("\n--- Match found ---\n");
            printEmployee(&employees[i]);
            found = 1;
        }
    }

    if (!found)
        printf("\nNo employee found for \"%s\".\n", key);
}

/* ---------- Salary breakdown by ID ---------- */
void calculateAndShowSalary(const Employee employees[], int count)
{
    if (count == 0) {
        printf("\nNo employees registered yet.\n");
        return;
    }

    char key[MAX_ID_LEN];
    readLine("Enter employee ID: ", key, sizeof key);

    int idx = findEmployeeIndex(employees, count, key);
    if (idx == -1) {
        printf("\nNo employee with ID %s.\n", key);
        return;
    }

    float gross, net;
    calculateSalary(&employees[idx], &gross, &net);

    printf("\nSalary breakdown for %s (%s)\n",
           employees[idx].name, employees[idx].id);
    printf("  Basic salary        : N$%10.2f\n", employees[idx].basicSalary);
    printf("  Housing allowance   : N$%10.2f\n", employees[idx].housingAllowance);
    printf("  Transport allowance : N$%10.2f\n", employees[idx].transportAllowance);
    printf("  ---------------------------------------\n");
    printf("  Gross salary        : N$%10.2f\n", gross);
    printf("  Tax                 : N$%10.2f\n", employees[idx].tax);
    printf("  ---------------------------------------\n");
    printf("  Net salary          : N$%10.2f\n", net);
}

/* ---------- Summary report ---------- */
void displayEmployeeReport(const Employee employees[], int count)
{
    if (count == 0) {
        printf("\nNo employees registered yet.\n");
        return;
    }

    float totalBasic = 0, totalHousing = 0, totalTransport = 0;
    float highest = employees[0].basicSalary;
    float lowest  = employees[0].basicSalary;

    for (int i = 0; i < count; i++) {
        totalBasic     += employees[i].basicSalary;
        totalHousing   += employees[i].housingAllowance;
        totalTransport += employees[i].transportAllowance;

        if (employees[i].basicSalary > highest) highest = employees[i].basicSalary;
        if (employees[i].basicSalary < lowest)  lowest  = employees[i].basicSalary;
    }

    printf("\n=========== EMPLOYEE REPORT ===========\n");
    printf("  Total employees             : %d\n", count);
    printf("  Average basic salary        : N$%.2f\n", totalBasic / count);
    printf("  Average housing allowance   : N$%.2f\n", totalHousing / count);
    printf("  Average transport allowance : N$%.2f\n", totalTransport / count);
    printf("  Highest basic salary        : N$%.2f\n", highest);
    printf("  Lowest  basic salary        : N$%.2f\n", lowest);
    printf("=======================================\n");
}
