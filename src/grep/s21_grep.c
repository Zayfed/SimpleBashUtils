#include <stdio.h>
#include <string.h>

#include "parcer.h"

int main(int argc, char *argv[]) {
  Flags flags = grep_parcer(argc, argv);
  read_file(argc, argv, flags);
}