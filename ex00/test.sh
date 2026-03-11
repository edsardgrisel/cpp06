#!/bin/bash

NC='\033[0m'
Red='\033[0;31m'
Green='\033[0;32m'
Yellow='\033[0;33m'
Blue='\033[0;34m'
Purple='\033[0;35m'
Cyan='\033[0;36m'
White='\033[0;37m'


# set -e

FILE=EX00

print_title() {
	printf "${Purple}\n"
	printf "=====================================\n"
	printf "        RUNNING EX00 TESTER          \n"
	printf "=====================================\n"
	printf "${NC}\n"
}

build() {
	echo "Running Make now..."
	make > /dev/null
	echo "Executable $FILE exists."
}





declare -A EXPECTED

# Char literal tests
EXPECTED["'a'"]=$'char: \'a\'\nint: 97\nfloat: 97.0f\ndouble: 97.0'
EXPECTED["'0'"]=$'char: \'a\'\nint: 48\nfloat: 48.0f\ndouble: 48.0'
EXPECTED["a"]=$'Error converting input.'

# Integer tests
EXPECTED["0"]=$'char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0'
EXPECTED["100"]=$'char: \'d\'\nint: 100\nfloat: 100.0f\ndouble: 100.0'
EXPECTED["1024"]=$'char: Non displayable\nint: 1024\nfloat: 1024.0f\ndouble: 1024.0'
EXPECTED["999999999999999"]=$'Integer overflow error.'


print_title
build

pass=0
fail=0

for input in "${!EXPECTED[@]}"; do
	actual="$(./EX00 "$input" 2>&1 || true)"
	expected="${EXPECTED[$input]}"

	if [[ "$actual" == "$expected" ]]; then
		printf "\n%bPASS%b input=%s\n" "$Green" "$NC" "$input"
		((pass++))
	else
		printf "\n%bFAIL%b input=%s\n" "$Red" "$NC" "$input"
		printf "%bExpected:%b\n%s\n" "$Yellow" "$NC" "$expected"
		printf "%bActual:%b\n%s\n" "$Cyan" "$NC" "$actual"
		((fail++))
	fi
done

printf "${Green} ${pass} tests passed. ${Red} ${fail} tests failed ${NC}\n"