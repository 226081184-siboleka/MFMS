#include <stdio.h>
#include <stdlib.h>

//Reference or link to the header files
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

//Navigation functions, please edit if wrong, I watched a YouTube tutorial
void DisplayMenu(void);
void ClearInput(void);

//Main menu
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
  printf("  Please choose a number from 1 to 6: "\n);

//Choosing number
int main(void){
  int Choice = 0
  while(1){
    DisplayMenu();
    //Check number that was input
    if(scanf("%d", &choice) != 1){
      printf("Please enter a whole number between 1 and 6.\n";
      ClearInput();
      continue;
    }
    switch(Choice){
      case 1:
        EmployeeMenu();
        break;
      case 2:
        BudgetMenu();
        break;
      case 3:
        SupplierMenu();
        break;
      case 4:
        AssetMenu();
        break;
      case 5:
        ReportsMenu();
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
