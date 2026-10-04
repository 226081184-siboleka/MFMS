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
