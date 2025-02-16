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
printf "${MAGENTA}Idris4work\t\n${DEF_COLOR}";
printf "${BLUE}\n-------------------------------------------------------------------------\n${DEF_COLOR}";

# Function to run tests with color-coded output
run_test() {
    ARG="$1"
    EXPECTED="$2"  # Expected outcome (OK, KO, or ERROR)
    
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
    printf "${BLUE}-------------------------------------------------------------------------${DEF_COLOR}\n"
}

# valgrind --leak-check=full ./push_swap 214748 "-3647"
# valgrind --leak-check=full ./push_swap 214748 "-3647" t"09" -
# valgrind --leak-check=full ./push_swap 214748 -"-3647"

# Sorted cases
run_test "1 2 3 4 5" OK
run_test "1 2 3 4 5 6" OK
run_test "1 2 3 4 5 6 7" OK
run_test "1 2 3 4 5 6 7 8" OK

# Reverse order cases
run_test "5 4 3 2 1" OK
run_test "6 5 4 3 2 1" OK
run_test "7 6 5 4 3 2 1" OK
run_test "8 7 6 5 4 3 2 1" OK

# Mixed order cases
run_test "4 2 5 1 3" OK
run_test "6 3 1 5 2 4" OK
run_test "7 2 5 1 6 4 3" OK
run_test "8 1 4 7 3 5 2 6" OK

# Duplicate values (should return ERROR)
run_test "5 5 3 2 1" ERROR
run_test "6 5 5 3 2 1" ERROR
run_test "7 6 5 4 4 3 2 1" ERROR
run_test "8 7 6 5 5 4 3 2 1" ERROR

# Negative numbers
run_test "-1 0 3 -2 5" OK
run_test "-10 -3 0 -1 4 2" OK
run_test "-5 -1 -4 -3 -2 0 1" OK
run_test "-8 -7 -6 -5 -4 -3 -2 -1" OK

# Mixed positive and negative numbers
run_test "-2 1 -3 5 0" OK
run_test "4 -5 6 1 -2 3" OK
run_test "-7 8 -3 1 6 4 2" OK
run_test "5 -8 4 -6 1 7 -2 3" OK

# Edge cases (min/max int)
run_test "-2147483648 0 5 -1 3" OK
run_test "2147483647 -2147483648 1 4 6 3" OK
run_test "-2147483648 2147483647 5 -4 0 1 3" OK
run_test "2147483647 -2147483648 8 6 2 4 3 1" OK

# Random cases
run_test "3 1 4 2 5" OK
run_test "2 6 1 3 7 4" OK
run_test "8 4 7 1 3 5 2" OK
run_test "5 2 8 3 1 7 4 6" OK

run_test "2147483647 0 4294967295" ERROR
run_test "2147483647 0 2147483648" ERROR
run_test "2147483647 0 2147483648" ERROR
run_test "2147483647 0 -2147483648" ERROR

run_test "2147483647 0 -2147483649" ERROR
