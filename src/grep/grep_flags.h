#ifndef GREP_FLAGS
#define GREP_FLAGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void grep(FILE *file, char *pattern, Flags flags, const char *name,
          int file_number);

#endif