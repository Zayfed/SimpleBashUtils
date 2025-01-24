#ifndef CAT_READ_H
#define CAT_READ_H

FILE* read_file(int argc, char* argv[]);
void table(const char* table[static 256]);
void flag_e(const char* table[static 256]);
void flag_t(const char* table[static 256]);
void flag_v(const char* table[static 256]);

#endif