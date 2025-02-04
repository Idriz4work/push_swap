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
printf "${CYAN}Idris4work\t\n${DEF_COLOR}";
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

# Test cases with 2-3 numbers
run_test "1 2" OK
run_test "1 2 3" OK
run_test "2 1" OK
run_test "3 2 1" OK
run_test "2 3 1" OK
run_test "3 1 2" OK
run_test "1 3 2" OK

# Duplicate values (should return ERROR)
run_test "2 2" ERROR
run_test "1 3 3" ERROR

# Negative numbers
run_test "-1 0" OK
run_test "0 -1 2" OK
run_test "-3 -1 -2" OK

# Mixed positive and negative numbers
run_test "-1 1" OK
run_test "3 -2 1" OK
run_test "-10 5 0" OK

# Edge cases (min/max int)
run_test "-2147483648 0" OK
run_test "2147483647 -2147483648" OK
run_test "-2147483648 2147483647 0" OK

# Single number
run_test "1" OK
run_test "-1000000" OK

# Large numbers
run_test "999999 1000000" OK
run_test "1000000 999999 1000001" OK

# Small numbers
run_test "-999999 -1000000" OK
run_test "-1000000 -999999 -1000001" OK

# Empty input (should return ERROR)
run_test "" ERROR

# Extra spaces (handling spaces properly)
run_test "  1   2  " OK
run_test "   3  2  1   " OK

# Non-numeric input (should output ERROR)
run_test "1 a 2" ERROR
run_test "hello 3 5" ERROR
run_test "1.5 2 3" ERROR

# Leading zeros
run_test "01 02 03" OK
run_test "0001 0002 0003" OK

# Mixed duplicates
run_test "3 3 2" ERROR
run_test "1 2 2" ERROR
run_test "100 200 200" ERROR

# Various sorting scenarios
run_test "1 2 3 4" OK
run_test "1 2 4 3" OK
run_test "1 3 2 4" OK
run_test "1 3 4 2" OK
run_test "1 4 2 3" OK
run_test "1 4 3 2" OK
run_test "2 1 3 4" OK
run_test "2 1 4 3" OK
run_test "3 1 2 4" OK
run_test "3 1 4 2" OK
run_test "4 1 2 3" OK
run_test "4 1 3 2" OK
run_test "2 3 1 4" OK
run_test "2 4 1 3" OK
run_test "3 2 1 4" OK
run_test "3 4 1 2" OK
run_test "4 2 1 3" OK
run_test "4 3 1 2" OK
run_test "2 3 4 1" OK
run_test "2 4 3 1" OK
run_test "3 2 4 1" OK
run_test "3 4 2 1" OK
run_test "4 2 3 1" OK
run_test "4 3 2 1" OK
run_test "9223372036854775807 18446744073709551615 -1" ERROR 

