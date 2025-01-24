#include <regex.h>
#include <stdio.h>

#include "parcer.h"

void grep(FILE *file, char *pattern, Flags flags, const char *name,
          int file_number) {
  char buffer[8192];
  regex_t regex;
  int count = 0, count_n = 0, find;
  regcomp(&regex, pattern, REG_EXTENDED);
  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    count_n++;
    if (flags.flag_i) {
      regfree(&regex);
      regcomp(&regex, pattern, REG_EXTENDED | REG_ICASE);
      find = regexec(&regex, buffer, 0, NULL, 0);
    } else
      find = regexec(&regex, buffer, 0, NULL, 0);
    if (flags.flag_v && find == REG_NOMATCH)
      find = 0;
    else if (flags.flag_v && find == 0)
      find = REG_NOMATCH;
    if (!find) {
      count++;
      if (file_number == 1 && !flags.flag_c && !flags.flag_l && !flags.flag_h)
        printf("%s:", name);
      if (flags.flag_n && !flags.flag_c && !flags.flag_l)
        printf("%i:", count_n);
      if (!flags.flag_c && !flags.flag_l) printf("%s", buffer);
    }
  }
  regfree(&regex);
  if (flags.flag_l) count = 1;
  if (flags.flag_c) {
    if (file_number == 1 && !flags.flag_h && !flags.flag_l) printf("%s:", name);
    if (!flags.flag_l) printf("%i\n", count);
  }
  if (flags.flag_l && count > 0) printf("%s\n", name);
  // if (!flags.flag_v && !flags.flag_c && !flags.flag_l) printf("\n");
}
