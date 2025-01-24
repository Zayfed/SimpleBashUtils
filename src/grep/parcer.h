#ifndef PARCER_H
#define PARCER_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  bool flag_e;
  bool flag_i;
  bool flag_v;
  bool flag_c;
  bool flag_l;
  bool flag_n;
  bool flag_h;
  bool flag_f;
  bool flag_s;
  bool flag_o;
} Flags;

Flags grep_parcer(int argc, char *argv[]);
void read_file(int argc, char *argv[], Flags flags);

#endif