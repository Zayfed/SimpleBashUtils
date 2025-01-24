SHELL := /bin/bash
flags = -Wall -Werror -Wextra

s21_cat:
	gcc $(flags) CatRead.c parcer.c s21_cat.c -o s21_cat

clean:
	rm s21_cat

rebuild: clean s21_cat
	make clean
	make s21_cat
test:
	-diff <(./s21_cat test.txt) <(cat test.txt)
	-diff <(./s21_cat -b test.txt) <(cat -b test.txt)
	-diff <(./s21_cat -e test.txt) <(cat -e test.txt)
	-diff <(./s21_cat -n test.txt) <(cat -n test.txt)
	-diff <(./s21_cat -s test.txt) <(cat -s test.txt)
	-diff <(./s21_cat -t test.txt) <(cat -t test.txt)
	-diff <(./s21_cat -b -n test.txt) <(cat -b -n test.txt)