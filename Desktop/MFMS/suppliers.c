#include <stdio.h>
#include <string.h>
#include "suppliers.h"

int supplierIDs[MAX_SUPPLIERS];
char supplierNames[MAX_SUPPLIERS][SUP_NAME_LEN];
char supplierEmails[MAX_SUPPLIERS][SUP_EMAIL_LEN];
char supplierPhones[MAX_SUPPLIERS][SUP_PHONE_LEN];
char supplierTowns[MAX_SUPPLIERS][SUP_TOWN_LEN];
int supplierCount = 0;

int getSupplierCount(void) {
    return supplierCount;
}
int getSupplierId(int index) {
    return supplierIDs[index];
}
const char *getSupplierName(int index) {
    return supplierNames[index];
}
int supplierExists(int id) {
    for (int i = 0; i < supplierCount; i++) {
        if (supplierIDs[i] == id) {
            return 1; // Supplier found
        }
    }
    return 0; // Supplier not found
}

void addSupplier(void) {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("Maximum limit of suppliers reached.\n");
        return;
    }

    int id;
    char name[SUP_NAME_LEN];
    char email[SUP_EMAIL_LEN];
    char phone[SUP_PHONE_LEN];
    char town[SUP_TOWN_LEN];

    printf("Add New Supplier:\n");
    printf("Enter Supplier ID:");
    if (scanf("%d", &id)!= 1){
        while(getchar() != '\n');
        printf("Invalid input: Please enter a positive integer.\n");
        return;
    }
    while (getchar() != '\n');

    if (id <= 0) {
        printf("Error: ID number must be psotive./n");
        return;
    }

    if (supplierExists(id)) {
        printf("Error: Supplier ID already exists./n", id);
        return;
    }

    printf("Supplier Name: ");
    fgets(name, SUP_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Email: ");
    fgets(email, SUP_EMAIL_LEN, stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Phone: ");
    fgets(phone, SUP_PHONE_LEN, stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Town: ");
    fgets(town, SUP_TOWN_LEN, stdin);
    town[strcspn(town, "\n")] = '\0';

    if (strlen(name) == 0) {
        printf("Name can not be empty.\n");
        return;
    }

     if (strlen(email) == 0) {
        printf("Email can not be empty.\n");
        return;
    }
    if (strchr(email, '@') == NULL ){
        printf("Email should have @.\n");
        return;
    }
    if (strlen(town) == 0){
        printf("Town can not be empty.\n");
        return;   
    }

    supplierIDs[supplierCount] = id;
    strcpy(supplierNames[supplierCount], name);
    strcpy(supplierEmails[supplierCount],email);
    strcpy(supplierPhones[supplierCount],phone);
    strcpy(supplierTowns[supplierCount],town);
    
    supplierCount++;

    printf("Supplier Added Successfully. Total suppliers:%d\n", supplierCount);
}
void supplierMenu(void) {
    int choice;
    do {
        printf("\nSupplier Management Menu:\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySuppliers();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                compareSuppliers();
                break;
            case 0:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}
 
