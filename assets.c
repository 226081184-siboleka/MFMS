#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "assets.h"

/* Asset Management module */

/* Limits */
#define MAX_ASSETS 100
#define ID_LEN 15
#define NAME_LEN 50
#define TYPE_LEN 30
#define DEPT_LEN 40
#define COND_LEN 20
#define INPUT_LEN 128

/* Parallel arrays: same index = same asset */
static char assetId[MAX_ASSETS][ID_LEN];
static char assetName[MAX_ASSETS][NAME_LEN];
static char assetType[MAX_ASSETS][TYPE_LEN];
static double assetValue[MAX_ASSETS];
static char assetDept[MAX_ASSETS][DEPT_LEN];
static char assetCondition[MAX_ASSETS][COND_LEN];
static int assetCount = 0;

/* Read a line safely and remove the newline */
static void readLine(const char *prompt, char *buffer, int size)
{
    int len, ch;

    printf("%s", prompt);
    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    len = (int)strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    } else {
        while ((ch = getchar()) != '\n' && ch != EOF) {
            ;
        }
    }
}

/* Keep asking until input is not blank */
static void readNonEmpty(const char *prompt, char *buffer, int size)
{
    int i, hasText;

    do {
        readLine(prompt, buffer, size);
        hasText = 0;
        for (i = 0; buffer[i] != '\0'; i++) {
            if (!isspace((unsigned char)buffer[i])) {
                hasText = 1;
                break;
            }
        }
        if (!hasText) {
            printf("  Error: this field cannot be empty.\n");
        }
    } while (!hasText);
}

/* Read a whole number within min and max */
static int readIntInRange(const char *prompt, int min, int max)
{
    char input[INPUT_LEN];
    char *end;
    long value;

    while (1) {
        readLine(prompt, input, INPUT_LEN);
        value = strtol(input, &end, 10);
        while (*end == ' ' || *end == '\t') {
            end++;
        }
        if (end != input && *end == '\0' && value >= min && value <= max) {
            return (int)value;
        }
        printf("  Invalid input. Enter a number between %d and %d.\n", min, max);
    }
}

/* Read a number greater than zero */
static double readPositiveDouble(const char *prompt)
{
    char input[INPUT_LEN];
    char *end;
    double value;

    while (1) {
        readLine(prompt, input, INPUT_LEN);
        value = strtod(input, &end);
        while (*end == ' ' || *end == '\t') {
            end++;
        }
        if (end == input || *end != '\0') {
            printf("  Invalid number.\n");
        } else if (value <= 0) {
            printf("  Value must be greater than zero.\n");
        } else {
            return value;
        }
    }
}

/* Convert text to upper case */
static void toUpperCase(char *text)
{
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        text[i] = (char)toupper((unsigned char)text[i]);
    }
}

/* Check if text contains part (ignores case) */
static int containsIgnoreCase(const char *text, const char *part)
{
    int textLen = (int)strlen(text);
    int partLen = (int)strlen(part);
    int i, j;

    if (partLen == 0 || partLen > textLen) {
        return 0;
    }
    for (i = 0; i <= textLen - partLen; i++) {
        for (j = 0; j < partLen; j++) {
            if (tolower((unsigned char)text[i + j]) !=
                tolower((unsigned char)part[j])) {
                break;
            }
        }
        if (j == partLen) {
            return 1;
        }
    }
    return 0;
}

/* Return index of asset ID, or -1 if not found */
static int findAssetById(const char *id)
{
    int i;
    for (i = 0; i < assetCount; i++) {
        if (strcmp(assetId[i], id) == 0) {
            return i;
        }
    }
    return -1;
}

/* Pick asset type from a menu */
static void chooseAssetType(char *dest)
{
    printf("\n1. Vehicle\n2. Computer\n3. Building\n");
    printf("4. Equipment\n5. Office Furniture\n6. Other\n");

    switch (readIntInRange("Select type (1-6): ", 1, 6)) {
        case 1: strcpy(dest, "Vehicle");          break;
        case 2: strcpy(dest, "Computer");         break;
        case 3: strcpy(dest, "Building");         break;
        case 4: strcpy(dest, "Equipment");        break;
        case 5: strcpy(dest, "Office Furniture"); break;
        default: readNonEmpty("Enter asset type: ", dest, TYPE_LEN); break;
    }
}

/* Pick asset condition from a menu */
static void chooseCondition(char *dest)
{
    printf("\n1. Excellent\n2. Good\n3. Fair\n4. Poor\n");

    switch (readIntInRange("Select condition (1-4): ", 1, 4)) {
        case 1: strcpy(dest, "Excellent"); break;
        case 2: strcpy(dest, "Good");      break;
        case 3: strcpy(dest, "Fair");      break;
        default: strcpy(dest, "Poor");     break;
    }
}

/* Print table heading */
static void printTableHeader(void)
{
    printf("\n%-10s %-22s %-17s %-14s %-18s %-10s\n",
           "ID", "Name", "Type", "Value (N$)", "Department", "Condition");
    printf("-----------------------------------------------------------"
           "-----------------------------\n");
}

/* Print one asset as a table row */
static void printAssetRow(int i)
{
    printf("%-10s %-22.22s %-17.17s %-14.2f %-18.18s %-10s\n",
           assetId[i], assetName[i], assetType[i],
           assetValue[i], assetDept[i], assetCondition[i]);
}

/* Add a new asset with validation */
void addAsset(void)
{
    char id[ID_LEN];
    int n;

    printf("\n--- ADD ASSET ---\n");
    if (assetCount >= MAX_ASSETS) {
        printf("The asset register is full.\n");
        return;
    }

    while (1) {
        readNonEmpty("Asset ID (e.g. AST001): ", id, ID_LEN);
        toUpperCase(id);
        if (strchr(id, ' ') != NULL) {
            printf("  Error: the ID must not contain spaces.\n");
        } else if (findAssetById(id) != -1) {
            printf("  Error: ID %s already exists.\n", id);
        } else {
            break;
        }
    }

    n = assetCount;
    strcpy(assetId[n], id);
    readNonEmpty("Asset name: ", assetName[n], NAME_LEN);
    chooseAssetType(assetType[n]);
    assetValue[n] = readPositiveDouble("Purchase value (N$): ");
    readNonEmpty("Department: ", assetDept[n], DEPT_LEN);
    chooseCondition(assetCondition[n]);

    assetCount++;
    printf("\nAsset %s added.\n", assetId[n]);
}

/* Show all assets */
void displayAssets(void)
{
    int i;

    printf("\n--- ASSET REGISTER ---\n");
    if (assetCount == 0) {
        printf("No assets registered yet.\n");
        return;
    }
    printTableHeader();
    for (i = 0; i < assetCount; i++) {
        printAssetRow(i);
    }
    printf("\nTotal assets: %d\n", assetCount);
}

/* Search by ID, name, type or department */
void searchAsset(void)
{
    char keyword[NAME_LEN];
    const char *field;
    int choice, i, index, found = 0;

    printf("\n--- SEARCH ASSETS ---\n");
    if (assetCount == 0) {
        printf("No assets registered yet.\n");
        return;
    }

    printf("1. By ID\n2. By name\n3. By type\n4. By department\n");
    choice = readIntInRange("Select option (1-4): ", 1, 4);
    readNonEmpty("Enter search text: ", keyword, NAME_LEN);

    if (choice == 1) {
        toUpperCase(keyword);
        index = findAssetById(keyword);
        if (index == -1) {
            printf("No asset found with ID %s.\n", keyword);
        } else {
            printTableHeader();
            printAssetRow(index);
        }
        return;
    }

    for (i = 0; i < assetCount; i++) {
        if (choice == 2) {
            field = assetName[i];
        } else if (choice == 3) {
            field = assetType[i];
        } else {
            field = assetDept[i];
        }
        if (containsIgnoreCase(field, keyword)) {
            if (!found) {
                printTableHeader();
            }
            printAssetRow(i);
            found++;
        }
    }
    if (found == 0) {
        printf("No assets matched \"%s\".\n", keyword);
    } else {
        printf("\n%d asset(s) found.\n", found);
    }
}

/* Used by the Reports module */
int getAssetCount(void)
{
    return assetCount;
}

double getTotalAssetValue(void)
{
    double total = 0.0;
    int i;

    for (i = 0; i < assetCount; i++) {
        total += assetValue[i];
    }
    return total;
}

/* Print asset report with totals */
void displayAssetReport(void)
{
    int i, poor = 0;

    printf("\n========================================\n");
    printf("              ASSET REPORT\n");
    printf("========================================\n");
    if (assetCount == 0) {
        printf("No assets registered yet.\n");
        return;
    }

    printTableHeader();
    for (i = 0; i < assetCount; i++) {
        printAssetRow(i);
        if (strcmp(assetCondition[i], "Poor") == 0) {
            poor++;
        }
    }
    printf("\nTotal assets      : %d\n", assetCount);
    printf("Total asset value : N$%.2f\n", getTotalAssetValue());
    printf("Assets in poor condition: %d\n", poor);
}

/* Asset module menu */
void assetMenu(void)
{
    int choice;

    do {
        printf("\n========================================\n");
        printf("            ASSET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Asset\n2. Display Assets\n3. Search Assets\n");
        printf("4. Asset Report\n5. Back to Main Menu\n");
        choice = readIntInRange("Enter your choice: ", 1, 5);

        switch (choice) {
            case 1: addAsset();           break;
            case 2: displayAssets();      break;
            case 3: searchAsset();        break;
            case 4: displayAssetReport(); break;
            default: break;
        }
    } while (choice != 5);
}
