#ifndef INPUT_H
#define INPUT_H

void  readLine(const char *prompt, char *buffer, int size);
float readNonNegativeFloat(const char *prompt);
int   readIntInRange(const char *prompt, int min, int max);

#endif