#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "input.h"

/* Called when stdin is closed (Ctrl+D / Ctrl+Z / end of piped input).
   Without this, every input loop below would spin forever. */
static void exitOnEof(void)
{
    printf("\n\nInput closed. Exiting.\n");
    exit(EXIT_SUCCESS);
}

/* Reads one line into buffer, strips the newline, and discards any extra
   characters that did not fit.
   Returns 1 = OK, 2 = OK but the line was too long and got truncated.
   Exits the program on EOF. */
static int readRawLine(char *buffer, int size)
{
    int status = 1;

    if (fgets(buffer, size, stdin) == NULL)
        exitOnEof();

    if (strchr(buffer, '\n') == NULL) {
        int c;
        int hadMore = 0;
        while ((c = getchar()) != '\n' && c != EOF)
            hadMore = 1;
        if (hadMore)
            status = 2;
    }

    buffer[strcspn(buffer, "\n")] = '\0';
    return status;
}

/* Removes leading and trailing whitespace in place. */
static void trim(char *s)
{
    size_t len = strlen(s);
    size_t start = 0;

    while (len > 0 && isspace((unsigned char)s[len - 1]))
        s[--len] = '\0';

    while (isspace((unsigned char)s[start]))
        start++;

    if (start > 0)
        memmove(s, s + start, len - start + 1);
}

void readLine(const char *prompt, char *buffer, int size)
{
    printf("%s", prompt);

    if (readRawLine(buffer, size) == 2)
        printf("  ! Input too long; kept the first %d characters.\n", size - 1);

    trim(buffer);
}

float readNonNegativeFloat(const char *prompt)
{
    char  line[100];
    char *end;
    float value;

    for (;;) {
        printf("%s", prompt);

        if (readRawLine(line, sizeof line) == 2) {
            printf("  ! Input too long.\n");
            continue;
        }
        trim(line);

        value = strtof(line, &end);

        if (end == line) {
            printf("  ! Please enter a number.\n");
            continue;
        }

        if (*end != '\0') {
            printf("  ! Invalid number.\n");
            continue;
        }

        /* strtof happily accepts "nan" and "inf"; NaN even slips past < 0. */
        if (!isfinite(value)) {
            printf("  ! Number out of range.\n");
            continue;
        }

        if (value < 0) {
            printf("  ! Value cannot be negative.\n");
            continue;
        }

        if (value == 0)
            value = 0.0f;   /* turns "-0" into a plain 0 */

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

        if (readRawLine(line, sizeof line) == 2) {
            printf("  ! Input too long.\n");
            continue;
        }
        trim(line);

        value = strtol(line, &end, 10);

        if (end == line) {
            printf("  ! Please enter a whole number.\n");
            continue;
        }

        if (*end != '\0') {
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
