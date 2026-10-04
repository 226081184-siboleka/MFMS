#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100
#define MAX_ID_LEN    20
#define MAX_NAME_LEN  60
#define MAX_DEPT_LEN  40
#define MAX_EMAIL_LEN 60
#define MAX_LEVEL_LEN 20

typedef struct {
    char  id[MAX_ID_LEN];
    char  name[MAX_NAME_LEN];
    char  department[MAX_DEPT_LEN];
    char  email[MAX_EMAIL_LEN];
    char  level[MAX_LEVEL_LEN];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
    float tax;
} Employee;

void addEmployee(Employee employees[], int *count);
void displayEmployees(const Employee employees[], int count);
void searchEmployee(const Employee employees[], int count);
void calculateAndShowSalary(const Employee employees[], int count);
void displayEmployeeReport(const Employee employees[], int count);
int  findEmployeeIndex(const Employee employees[], int count, const char *id);
void calculateSalary(const Employee *e, float *gross, float *net);

#endif