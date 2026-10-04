#include <stdio.h>
#include <string.h>
#include "suppliers.h"

int supplierIDs[MAX_SUPPLIERS];
char supplierNames[MAX_SUPPLIERS][SUP_NAME_LEN];
char supplierEmails[MAX_SUPPLIERS][SUP_EMAIL_LEN];
char supplierPhones[MAX_SUPPLIERS][SUP_PHONE_LEN];
int supplierTowns[MAX_SUPPLIERS][SUP_TOWN_LEN];
int supplierCount = 0;

int getSupplierCount(void) {
    return supplierCount;
}