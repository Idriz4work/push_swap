#!/bin/bash

# -=-=-=-=-	COLORS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_COLOR='\033[0;39m'
BLACK='\033[0;30m'
RED='\033[1;91m'      # ❌ KO
GREEN='\033[1;92m'    # ✅ OK
YELLOW='\033[0;93m'   # ⚠️ Error
BLUE='\033[0;94m'
MAGENTA='\033[0;95m'
CYAN='\033[0;96m'
GRAY='\033[0;90m'
WHITE='\033[0;97m'

printf "${BLUE}\n-------------------------------------------------------------------------\n${DEF_COLOR}";
printf "${YELLOW}\n\t\tTEST MADE BY: ${DEF_COLOR}";
printf "${CYAN}Idriz4work\t\n${DEF_COLOR}";
printf "${BLUE}\n-------------------------------------------------------------------------\n${DEF_COLOR}";

# Function to run tests with color-coded output
run_test() {
    ARG="$1"
    EXPECTED="$2"  # Expected outcome (OK, KO, or ERROR)

	# Store push_swap output in a variable
    OPERATIONS=$(.././push_swap $ARG)
    
    # Count the number of operations
    OP_COUNT=$(echo "$OPERATIONS" | wc -l)

    printf "${CYAN}Running Test: '$ARG'${DEF_COLOR}\n"

    RESULT=$(.././push_swap $ARG | ./checker_linux $ARG 2>&1) # Capture output

    if [[ "$RESULT" == "OK" ]]; then
        if [[ "$EXPECTED" == "OK" ]]; then
            printf "${GREEN}✅ OK${DEF_COLOR}\n"
        else
            printf "${YELLOW}⚠️  Expected ERROR but got OK${DEF_COLOR}\n"
        fi
    elif [[ "$RESULT" == "KO" ]]; then
        if [[ "$EXPECTED" == "KO" ]]; then
            printf "${GREEN}✅ Expected KO${DEF_COLOR}\n"
        else
            printf "${RED}❌ KO${DEF_COLOR}\n"
        fi
    else
        if [[ "$EXPECTED" == "ERROR" ]]; then
            printf "${GREEN}✅ Expected ERROR${DEF_COLOR}\n"
        else
            printf "${YELLOW}⚠️ Unexpected Error: $RESULT${DEF_COLOR}\n"
        fi
    fi
	printf "${YELLOW}------------------\ ${GREEN}[NUMBER OF OPERATIONS:${MAGENTA} ${OP_COUNT}] ${YELLOW}--------------\n"
    printf "${BLUE}-------------------------------------------------------------------------${DEF_COLOR}\n"
}

run_onetwp(){
	# Basic single numbers
	run_test "42" OK
	run_test "0" OK
	run_test "-42" OK
	run_test "2147483647" OK
	run_test "-2147483648" OK

	# Two number combinations (all variations)
	run_test "1 2" OK
	run_test "2 1" OK
	run_test "-1 1" OK
	run_test "1 -1" OK
	run_test "-2 -1" OK
	run_test "-1 -2" OK
	run_test "0 1" OK
	run_test "1 0" OK
	run_test "-1 0" OK
	run_test "0 -1" OK
	run_test "2147483647 -2147483648" OK
	run_test "-2147483648 2147483647" OK
}

run_three(){

	# Three number combinations (all variations)
	run_test "1 2 3" OK
	run_test "1 3 2" OK
	run_test "2 1 3" OK
	run_test "2 3 1" OK
	run_test "3 1 2" OK
	run_test "3 2 1" OK

	# Mixed positive/negative three numbers
	run_test "-1 0 1" OK
	run_test "-1 1 0" OK
	run_test "0 -1 1" OK
	run_test "0 1 -1" OK
	run_test "1 -1 0" OK
	run_test "1 0 -1" OK

	# Error cases - duplicates
	run_test "1 1" ERROR
	run_test "0 0" ERROR
	run_test "-1 -1" ERROR
	run_test "1 2 2" ERROR
	run_test "2 2 1" ERROR
	run_test "1 1 2" ERROR
	run_test "0 0 0" ERROR

	# Error cases - invalid input
	run_test "a" ERROR
	run_test "1 b" ERROR
	run_test "1 2 c" ERROR
	run_test "1.5" ERROR
	run_test "1 2.5" ERROR
	run_test "1.0 2.0" ERROR
	run_test "" ERROR
	run_test " " ERROR

	# Spacing variations
	run_test "1  2" OK
	run_test " 1 2 " OK
	run_test "  1  2  3  " OK
	run_test "1   2   3" OK

	# Leading zeros
	run_test "01" OK
	run_test "01 02" OK
	run_test "001 002" OK
	run_test "01 02 03" OK
	run_test "001 002 003" OK

	# Extreme value combinations
	run_test "2147483647 0" OK
	run_test "0 2147483647" OK
	run_test "-2147483648 0" OK
	run_test "0 -2147483648" OK
	run_test "2147483647 -2147483648 0" OK
	run_test "-2147483648 0 2147483647" OK
	run_test "0 2147483647 -2147483648" OK

	# Large number combinations
	run_test "999999 1000000" OK
	run_test "1000000 999999" OK
	run_test "999998 999999 1000000" OK
	run_test "1000000 999999 999998" OK

	# Small number combinations
	run_test "-999999 -1000000" OK
	run_test "-1000000 -999999" OK
	run_test "-999999 -1000000 -1000001" OK
	run_test "-1000001 -1000000 -999999" OK

	# Mixed number lengths
	run_test "1 22" OK
	run_test "333 22 1" OK
	run_test "1 4444 333" OK
	run_test "55555 1 22" OK

	# Zero with positive and negative
	run_test "0 1" OK
	run_test "1 0" OK
	run_test "-1 0" OK
	run_test "0 -1" OK
	run_test "0 1 -1" OK
	run_test "0 -1 1" OK
	run_test "-1 0 1" OK
	run_test "1 0 -1" OK

	# Error cases - overflow values
	run_test "9223372036854775807 1" ERROR
	run_test "18446744073709551615 -1" ERROR
	run_test "9223372036854775808" ERROR
	run_test "-9223372036854775809" ERROR

	# Multiple spaces and tabs
	run_test "1	2" OK
	run_test "1	2	3" OK
	run_test "1 	 2 	 3" OK

	# Mixed error cases
	run_test "1 1 a" ERROR
	run_test "a 1 1" ERROR
	run_test "1.0 1 2" ERROR
	run_test "1 2.0 3" ERROR
	run_test "1 2 2.0" ERROR
}

run_four(){
	# Basic 4 number combinations (all permutations)
	run_test "1 2 3 4" OK
	run_test "1 2 4 3" OK
	run_test "1 3 2 4" OK
	run_test "1 3 4 2" OK
	run_test "1 4 2 3" OK
	run_test "1 4 3 2" OK
	run_test "2 1 3 4" OK
	run_test "2 1 4 3" OK
	run_test "2 3 1 4" OK
	run_test "2 3 4 1" OK
	run_test "2 4 1 3" OK
	run_test "2 4 3 1" OK
	run_test "3 1 2 4" OK
	run_test "3 1 4 2" OK
	run_test "3 2 1 4" OK
	run_test "3 2 4 1" OK
	run_test "3 4 1 2" OK
	run_test "3 4 2 1" OK
	run_test "4 1 2 3" OK
	run_test "4 1 3 2" OK
	run_test "4 2 1 3" OK
	run_test "4 2 3 1" OK
	run_test "4 3 1 2" OK
	run_test "4 3 2 1" OK

	# Mixed positive/negative combinations
	run_test "-1 -2 1 2" OK
	run_test "-2 -1 1 2" OK
	run_test "-1 1 -2 2" OK
	run_test "1 -1 2 -2" OK
	run_test "-2 1 -1 2" OK
	run_test "2 -2 1 -1" OK

	# Zero combinations
	run_test "0 1 2 3" OK
	run_test "1 0 2 3" OK
	run_test "1 2 0 3" OK
	run_test "1 2 3 0" OK
	run_test "-1 0 1 2" OK
	run_test "0 -2 -1 1" OK

	# Large number combinations
	run_test "2147483647 -2147483648 0 1" OK
	run_test "-2147483648 2147483647 1 0" OK
	run_test "999999 1000000 1000001 1000002" OK
	run_test "-999999 -1000000 -1000001 -1000002" OK

	# Error cases - duplicates
	run_test "1 1 2 3" ERROR
	run_test "1 2 2 3" ERROR
	run_test "1 2 3 3" ERROR
	run_test "1 2 1 3" ERROR
	run_test "2 2 2 2" ERROR

	# Leading zeros
	run_test "01 02 03 04" OK
	run_test "001 002 003 004" OK
	run_test "0001 0002 0003 0004" OK

	# Spacing variations
	run_test "1  2  3  4" OK
	run_test " 1 2 3 4 " OK
	run_test "  1   2   3   4  " OK

	# Error cases - invalid input
	run_test "1 2 3 a" ERROR
	run_test "1 2 a 3" ERROR
	run_test "1 a 2 3" ERROR
	run_test "a 1 2 3" ERROR
	run_test "1 2 3 4.0" ERROR
	run_test "1.0 2 3 4" ERROR

	# Mixed number lengths
	run_test "1 22 333 4444" OK
	run_test "4444 333 22 1" OK
	run_test "999 88 7777 6" OK

	# Extreme value combinations
	run_test "2147483647 -2147483648 1 0" OK
	run_test "-2147483648 0 2147483647 1" OK
	run_test "1 2147483647 -2147483648 0" OK

	# Error cases - overflow
	run_test "9223372036854775807 1 2 3" ERROR
	run_test "1 18446744073709551615 2 3" ERROR
	run_test "9223372036854775808 1 2 3" ERROR

}


# test for five numbers
run_test "1 2 3 4 5" OK
run_test "1 2 3 5 4" OK
run_test "1 2 4 3 5" OK
run_test "1 2 4 5 3" OK
run_test "1 2 5 3 4" OK
run_test "1 2 5 4 3" OK
run_test "1 3 2 4 5" OK
run_test "1 3 2 5 4" OK
run_test "1 3 4 2 5" OK
run_test "1 3 4 5 2" OK
run_test "1 3 5 2 4" OK
run_test "1 3 5 4 2" OK
run_test "1 4 2 3 5" OK
run_test "1 4 2 5 3" OK
run_test "1 4 3 2 5" OK
run_test "1 4 3 5 2" OK
run_test "1 4 5 2 3" OK
run_test "1 4 5 3 2" OK
run_test "1 5 2 3 4" OK
run_test "1 5 2 4 3" OK
run_test "1 5 3 2 4" OK
run_test "1 5 3 4 2" OK
run_test "1 5 4 2 3" OK
run_test "1 5 4 3 2" OK
run_test "2 1 3 4 5" OK
run_test "2 1 3 5 4" OK
run_test "2 1 4 3 5" OK
run_test "2 1 4 5 3" OK
run_test "2 1 5 3 4" OK
run_test "2 1 5 4 3" OK
run_test "2 3 1 4 5" OK
run_test "2 3 1 5 4" OK
run_test "2 3 4 1 5" OK
run_test "2 3 4 5 1" OK
run_test "2 3 5 1 4" OK
run_test "2 3 5 4 1" OK
run_test "2 4 1 3 5" OK
run_test "2 4 1 5 3" OK
run_test "2 4 3 1 5" OK
run_test "2 4 3 5 1" OK
run_test "2 4 5 1 3" OK
run_test "2 4 5 3 1" OK
run_test "2 5 1 3 4" OK
run_test "2 5 1 4 3" OK
run_test "2 5 3 1 4" OK
run_test "2 5 3 4 1" OK
run_test "2 5 4 1 3" OK
run_test "2 5 4 3 1" OK
run_test "3 1 2 4 5" OK
run_test "3 1 2 5 4" OK
run_test "3 1 4 2 5" OK
run_test "3 1 4 5 2" OK
run_test "3 1 5 2 4" OK
run_test "3 1 5 4 2" OK
run_test "3 2 1 4 5" OK
run_test "3 2 1 5 4" OK
run_test "3 2 4 1 5" OK
run_test "3 2 4 5 1" OK
run_test "3 2 5 1 4" OK
run_test "3 2 5 4 1" OK
run_test "3 4 1 2 5" OK
run_test "3 4 1 5 2" OK
run_test "3 4 2 1 5" OK
run_test "3 4 2 5 1" OK
run_test "3 4 5 1 2" OK
run_test "3 4 5 2 1" OK
run_test "3 5 1 2 4" OK
run_test "3 5 1 4 2" OK
run_test "3 5 2 1 4" OK
run_test "3 5 2 4 1" OK
run_test "3 5 4 1 2" OK
run_test "3 5 4 2 1" OK
run_test "4 1 2 3 5" OK
run_test "4 1 2 5 3" OK
run_test "4 1 3 2 5" OK
run_test "4 1 3 5 2" OK
run_test "4 1 5 2 3" OK
run_test "4 1 5 3 2" OK
run_test "4 2 1 3 5" OK
run_test "4 2 1 5 3" OK
run_test "4 2 3 1 5" OK
run_test "4 2 3 5 1" OK
run_test "4 2 5 1 3" OK
run_test "4 2 5 3 1" OK
run_test "4 3 1 2 5" OK
run_test "4 3 1 5 2" OK
run_test "4 3 2 1 5" OK
run_test "4 3 2 5 1" OK
run_test "4 3 5 1 2" OK
run_test "4 3 5 2 1" OK
run_test "4 5 1 2 3" OK
run_test "4 5 1 3 2" OK
run_test "4 5 2 1 3" OK
run_test "4 5 2 3 1" OK
run_test "4 5 3 1 2" OK
run_test "4 5 3 2 1" OK
run_test "5 1 2 3 4" OK
run_test "5 1 2 4 3" OK
run_test "5 1 3 2 4" OK
run_test "5 1 3 4 2" OK
run_test "5 1 4 2 3" OK
run_test "5 1 4 3 2" OK
run_test "5 2 1 3 4" OK
run_test "5 2 1 4 3" OK
run_test "5 2 3 1 4" OK
run_test "5 2 3 4 1" OK
run_test "5 2 4 1 3" OK
run_test "5 2 4 3 1" OK
run_test "5 3 1 2 4" OK
run_test "5 3 1 4 2" OK
run_test "5 3 2 1 4" OK
run_test "5 3 2 4 1" OK
run_test "5 3 4 1 2" OK
run_test "5 3 4 2 1" OK
run_test "5 4 1 2 3" OK
run_test "5 4 1 3 2" OK
run_test "5 4 2 1 3" OK
run_test "5 4 2 3 1" OK
run_test "5 4 3 1 2" OK
run_test "5 4 3 2 1" OK
