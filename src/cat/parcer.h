#ifndef PARCER_H
#define PARCER_H
#include <stdbool.h>

typedef struct {
  bool flag_b;
  bool flag_e;
  bool flag_n;
  bool flag_s;
  bool flag_t;
  bool flag_v;
} Flags;

Flags cat_parcer(int argc, char *argv[]);

#endif