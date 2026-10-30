#include <stdio.h>
#include <stdlib.h>

//Reference or link to the header files
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

//Navigation functions
void DisplayMenu(void);
void ClearInput(void);

//Main menu display function
void DisplayMenu(void){
    printf("=========================================\n");
    printf("  MUNICIPAL FINANCIAL MANAGEMENT SYSTEM  \n");
    printf("=========================================\n");
    printf("  1. Employee management\n");
    printf("  2. Budget management\n");
    printf("  3. Supplier management\n");
    printf("  4. Asset management\n");
    printf("  5. Report\n");
    printf("  6. Exit\n");
    printf("-----------------------------------------\n");
    printf("  Please choose a number from 1 to 6: ");
} // <-- Added missing closing brace here!

//Main function
int main(void){
    int Choice = 0;
    
    while(1){
        DisplayMenu();
        
        // Check number that was input (Fixed case to Match 'Choice')
        if(scanf("%d", &Choice) != 1){
            printf("Please enter a whole number between 1 and 6.\n"); // Fixed semicolon position
            ClearInput();
            continue;
        }
        
        switch(Choice){
            case 1:
                employeeMenu(); // Make sure this matches your header casing
                break;
            case 2:
                budgetMenu();
                break;
            case 3:
                supplierMenu();
                break;
            case 4:
                assetMenu();
                break;
            case 5:
                reportsMenu();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Please choose a number between 1 and 6: \n");
                break;
        }
    }
    return 0;
}
