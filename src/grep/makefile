SHELL := /bin/bash
flags = -Wall -Werror -Wextra

s21_grep:
	gcc $(flags) grep_flags.c parcer.c s21_grep.c -o s21_grep

clean:
	rm s21_grep

rebuild: clean s21_grep
	make clean
	make s21_grep
test:
	./grep_test.sh