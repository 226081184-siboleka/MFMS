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

    printf("Supplier Added Successfully. Total suppliers: %d\n", supplierCount);
}

void displaySuppliers(void) {
    if (supplierCount == 0) {
        printf("No Suppliers avaiable.\n");
        return;
    }
    printf("\n-----Suppliers-----\n");
    prinf("%-5s %-22s %-25s %-15s %-15s\n", "ID", "Name", "Email", "Phone", "Town");
    printf("\n------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i<supplierCount; i++) {
        printf("%-5d %-22s %-25s %-15s %-15s\n", supplierIDs[i],supplierNames[i],supplierEmails[i],supplierPhones[i],supplierTowns[i]);
    }
}

void searchSupplier(void) {
    if (supplierCount == 0) {
        printf("\nNo suppliers to search for\n");
        return;
    }
    
    int mode; int id; char term[SUP_NAME_LEN];
    printf("\n---- Search Supplier ----\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("Choice: ");
    if (scanf("%d", &mode) != 1) {
        while (getchar() != '\n');
        printf("Invaild input.\n");
        return;
    }
    while (getchar() != '\n');

    if (mode == 1) {
        printf("Enter Supplier ID: ");
        if (scanf("%d", &id) != 1) {
            while (getchar() != '\n');
            printf("Invaild ID.\n");
            return;
        }
        while (getchar() != '\n');

        for (int i = 0; i < supplierCount; i++) {
            if (supplierIDs[i] == id) {
                printf("\nSupplier found:\n");
                printf("ID:  %D\n", supplierIDs[i]);
                printf("Name: %s\n", supplierNames[i]);
                printf("Email: %s\n", supplierEmails[i]);
                printf("Phone: %s\n", supplierPhones[i]);
                printf("Town: %s\n", supplierTowns[i]);
                return;
            }
        }
        printf("No supplier with that ID found.\n");
    } else if (mode == 2) {
        printf("Enter Supplier Name: ");
        fgets(term, SUP_NAME_LEN, stdin);
        term[strcspn(term, "\n")] = '\0';

        if (strlen(term) == 0){
            printf("search term cant be empty.\n");
            return;
        }

        int found = 0;
        printf("\n Matches\n");
        for (int i = 0; i < supplierCount; i++) {
            if (strstr(supplierNames[i], term) != NULL) {
                printf(" - [%d] %s | %s | %s | %s\n", supplierIDs[i], supplierNames[i], supplierEmails[i], supplierPhones[i], supplierTowns[i]);
                found = 1;
            }
        }
        if (!found) {
            printf("No matches found \"%s" "found.\n", term);
        }
    } else {
        printf("Invaild search choice.\n");
    }
}

void compareSupplier(void) {
    if (supplierCount < 2) {
        printf("\nNeed at least two suppliers.\n");
        return;
    }
    int id1, id2;
    int idx1 = -1; 
    int idx2 = -1;
    printf("\n----Compare two suppliers----\n");
    printf("Enter first supplier ID: ");
    if (scanf("%d", &id1) != 1) {
        while (getchar() != '\n');
        printf("Invaild ID.\n");
        return;
    }
    while (getchar() != '\n');

    printf("Enter second supplier ID: ");
    if (scanf("%d", &id2) != 1) {
        while (getchar() != '\n');
        printf("Invaild ID.\n");
        return;
    }
    while (getchar() != '\n');

    for (int i = 0; i < supplierCount; i++) {
        if (supplierIDs[i] == id1) idx1 = i;
        if (supplierIDs[i] == id2) idx2 = i;
    }
    if (idx1 == -1) {
        printf("No Supplier with ID %d.\n", id1);
        return;
    }
     if (idx2 == -1) {
        printf("No Supplier with ID %d.\n", id2);
        return;
    }
    printf("\n%-12s %-25s %-25s\n", "Field", "Supplier A", "Supplier B");
    printf("---------------------------------------------------------------------------\n");

    printf("%-12s %-25d %-25d\n", "ID", supplierIDs[idx1], supplierIDs[idx2]);
    printf("%-12s %-25s %-25s\n", "Name", supplierNames[idx1], supplierNames[idx2]);
    printf("%-12s %-25s %-25s\n", "Email", supplierEmails[idx1], supplierEmails[idx2]);
    printf("%-12s %-25s %-25s\n", "Phone", supplierPhones[idx1], supplierPhones[idx2]);
    printf("%-12s %-25s %-25s\n", "Town", supplierTowns[idx1], supplierTowns[idx2]);

    print("\n Comparison Summary\n");
    if (strcmp(supplierNames[idx1], supplierNames[idx2]) == 0) {
        printf("Names are identical.\n");
    } else {
        printf("Names are different.\n");
    }

    if (strcmp(supplierTowns[idx1], supplierTowns[idx2]) == 0) {
        printf("Operate in the same town:%s\n", supplierTowns[idx1]);
    } else {
        printf("Operate in different towns (%s vs %s)\n", supplierTowns[idx1], supplierTowns[idx2]);
    }

    if (strcmp(supplierEmails[idx1], supplierEmails[idx2]) == 0) {
        printf("Emails are identical. (potential duplicate)\n");
    } else {
        printf("Emails  are different.\n");
    }
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
 
