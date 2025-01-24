#include "parcer.h"

#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grep_flags.h"

Flags grep_parcer(int argc, char *argv[]) {
  struct option longOpt[] = {{0, 0, 0, 0}};

  int curFlag = getopt_long(argc, argv, "eivclnhsfo", longOpt, NULL);
  Flags flags = {false, false, false, false, false,
                 false, false, false, false, false};
  for (; curFlag != -1;
       curFlag = getopt_long(argc, argv, "eivclnhsfo", longOpt, NULL)) {
    switch (curFlag) {
      case 'e':
        flags.flag_e = true;
        break;
      case 'i':
        flags.flag_i = true;
        break;
      case 'v':
        flags.flag_v = true;
        break;
      case 'c':
        flags.flag_c = true;
        break;
      case 'l':
        flags.flag_l = true;
        break;
      case 'n':
        flags.flag_n = true;
        break;
      case 'h':
        flags.flag_h = true;
        break;
      case 's':
        flags.flag_s = true;
        break;
      case 'f':
        flags.flag_f = true;
        break;
      case 'o':
        flags.flag_o = true;
        break;
    }
  }
  return flags;
}

void read_file(int argc, char *argv[], Flags flags) {
  FILE *file = NULL;
  char **pattern = &argv[1];
  int file_number = 0;
  while (pattern != &argv[argc] && pattern[0][0] == '-') ++pattern;
  for (char **name = pattern + 1; name != &argv[argc]; ++name) {
    char **test = name;
    if (++test != &argv[argc]) file_number = 1;
    if (**name != '-') {
      file = fopen(*name, "r");
      const char *name_f = *name;
      if (file == NULL && !flags.flag_s)
        fprintf(stderr, "Ошибка при открытии файла\n");
      else if (pattern == &argv[argc])
        fprintf(stderr, "Ошибка при чтении паттерна\n");
      else if (file != NULL) {
        grep(file, *pattern, flags, name_f, file_number);
        fclose(file);
      }
    }
  }
}