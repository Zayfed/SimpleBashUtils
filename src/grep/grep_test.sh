#!/bin/bash

GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
RESETCOLOR=$(tput sgr0)
my=$(./s21_grep -i This test.txt ytest2.txt)
grep=$(grep -i This test.txt ytest2.txt)

if [ "$my" == "$grep" ]; then
    echo "test -i ${GREEN}done${RESETCOLOR}"
else
    echo "test -i ${RED}failed${RESETCOLOR}"
fi


my=$(./s21_grep -v This test.txt ytest2.txt)
grep=$(grep -v This test.txt ytest2.txt)
if [ "$my" == "$grep" ]; then
    echo "test -v ${GREEN}done${RESETCOLOR}"
else
    echo "test -v ${RED}failed${RESETCOLOR}"
fi

my=$(./s21_grep -c This test.txt ytest2.txt)
grep=$(grep -c This test.txt ytest2.txt)
if [ "$my" == "$grep" ]; then
    echo "test -c ${GREEN}done${RESETCOLOR}"
else
    echo "test -c ${RED}failed${RESETCOLOR}"
fi

my=$(./s21_grep -l This test.txt ytest2.txt)
grep=$(grep -l This test.txt ytest2.txt)
if [ "$my" == "$grep" ]; then
    echo "test -l ${GREEN}done${RESETCOLOR}"
else
    echo "test -l ${RED}failed${RESETCOLOR}"
fi

my=$(./s21_grep -n This test.txt ytest2.txt)
grep=$(grep -n This test.txt ytest2.txt)
if [ "$my" == "$grep" ]; then
    echo "test -n ${GREEN}done${RESETCOLOR}"
else
    echo "test -n ${RED}failed${RESETCOLOR}"
fi

my=$(./s21_grep -h This test.txt ytest2.txt)
grep=$(grep -h This test.txt ytest2.txt)
if [ "$my" == "$grep" ]; then
    echo "test -h ${GREEN}done${RESETCOLOR}"
else
    echo "test -h ${RED}failed${RESETCOLOR}"
fi

my=$(./s21_grep -s This test.txt ytest2.txt)
grep=$(grep -s This test.txt ytest2.txt)
if [ "$my" == "$grep" ]; then
    echo "test -s ${GREEN}done${RESETCOLOR}"
else
    echo "test -s ${RED}failed${RESETCOLOR}"
fi

