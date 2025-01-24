#include <stdio.h>
#include <string.h>

#include "CatRead.h"
#include "parcer.h"

void cat(FILE *file, Flags cat_flags, const char *cat_table[static 256]);

int main(int argc, char *argv[]) {
  Flags flags = cat_parcer(argc, argv);
  const char *cat_table[256];
  table(cat_table);
  if (flags.flag_e) {
    flag_e(cat_table);
  }
  if (flags.flag_t) {
    flag_t(cat_table);
  }
  if (flags.flag_v) {
    flag_v(cat_table);
  }
  FILE *file = read_file(argc, argv);
  if (file == NULL) {
    printf("Ошибка чтения файла\n");
  } else {
    cat(file, flags, cat_table);
    fclose(file);
  }
}

void cat(FILE *file, Flags cat_flags, const char *cat_table[static 256]) {
  int c;
  int line = 1;
  int empty = 0;
  int last = '\n';
  while ((c = fgetc(file)) != EOF) {
    if (cat_flags.flag_b) {
      if (c != '\n' && last == '\n') printf("%6i\t", line++);
    } else if (cat_flags.flag_n && last == '\n' && !cat_flags.flag_s) {
      printf("%6i\t", line++);
    }

    if (c == '\n' && last == '\n')
      empty++;
    else
      empty = 0;
    if (cat_flags.flag_s && empty > 1 && last == '\n') {
    } else {
      printf("%s", cat_table[c]);
    }
    last = c;
  }
}
