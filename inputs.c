#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input.h"

void readLine(const char *prompt, char *buffer, int size)
{
    printf("%s", prompt);

    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }

    if (strchr(buffer, '\n') == NULL) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }

    buffer[strcspn(buffer, "\n")] = '\0';
}

float readNonNegativeFloat(const char *prompt)
{
    char  line[100];
    char *end;
    float value;

    for (;;) {
        printf("%s", prompt);

        if (fgets(line, sizeof line, stdin) == NULL) {
            printf("  ! Input error, try again.\n");
            continue;
        }

        value = strtof(line, &end);

        if (end == line) {
            printf("  ! Please enter a number.\n");
            continue;
        }

        while (*end == ' ' || *end == '\t') end++;
        if (*end != '\n' && *end != '\0') {
            printf("  ! Invalid number.\n");
            continue;
        }

        if (value < 0) {
            printf("  ! Value cannot be negative.\n");
            continue;
        }

        return value;
    }
}

int readIntInRange(const char *prompt, int min, int max)
{
    char  line[100];
    char *end;
    long  value;

    for (;;) {
        printf("%s", prompt);

        if (fgets(line, sizeof line, stdin) == NULL) {
            printf("  ! Input error, try again.\n");
            continue;
        }

        value = strtol(line, &end, 10);

        if (end == line) {
            printf("  ! Please enter a whole number.\n");
            continue;
        }

        while (*end == ' ' || *end == '\t') end++;
        if (*end != '\n' && *end != '\0') {
            printf("  ! Invalid number.\n");
            continue;
        }

        if (value < min || value > max) {
            printf("  ! Enter a value between %d and %d.\n", min, max);
            continue;
        }

        return (int)value;
    }
}
