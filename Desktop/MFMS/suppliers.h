/*supplier.h*/
#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100
#define SUP_NAME_LEN 50
#define SUP_EMAIL_LEN 50
#define SUP_PHONE_LEN 20 
#define SUP_TOWN_LEN 50

void supplierMenu(void);
void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);
void compareSuppliers(void);

int getSupplierCount(void);
int getSupplierId(int index);
int supplierExists(int id);
const char *getSupplierName(int index);
#endif