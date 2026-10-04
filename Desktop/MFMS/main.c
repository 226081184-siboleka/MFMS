#include <stdio.h>

//Reference or link to the header files
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

//Navigation functions, please edit if wrong, I watched a YouTube tutorial
void DisplayMenu(void);
void ClearInput(void);

int main(void){
  int Choice = 0
  while(1){
    DisplayMenu();
    //Check number that was input
    if(scanf("%d", &choice) != 1){
      printf("Please enter a whole number between 1 and 6.\n";
