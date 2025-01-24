#include "parcer.h"

#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>

Flags cat_parcer(int argc, char *argv[]) {
  struct option longOpt[] = {{"number-nonblank", 0, NULL, 'b'},
                             {"number", 0, NULL, 'n'},
                             {"squeeze-blank", 0, NULL, 's'},
                             {0, 0, 0, 0}};

  int curFlag = getopt_long(argc, argv, "benstvET", longOpt, NULL);
  Flags flags = {false, false, false, false, false, false};
  for (; curFlag != -1;
       curFlag = getopt_long(argc, argv, "benstvET", longOpt, NULL)) {
    switch (curFlag) {
      case 'b':
        flags.flag_b = true;
        break;
      case 'e':
        flags.flag_e = true;
        flags.flag_v = true;
        break;
      case 'n':
        flags.flag_n = true;
        break;
      case 's':
        flags.flag_s = true;
        break;
      case 't':
        flags.flag_t = true;
        flags.flag_v = true;
        break;
      case 'v':
        flags.flag_v = true;
        break;
      case 'E':
        flags.flag_e = true;
        break;
      case 'T':
        flags.flag_t = true;
        break;
    }
  }
  return flags;
}
