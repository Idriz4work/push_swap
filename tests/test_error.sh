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
#!/bin/bash

# -=-=-=-=- COLORS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #
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

printf "${BLUE}\n-------------------------------------------------------------------------\n${DEF_COLOR}"
printf "${YELLOW}\n\t\tTEST MADE BY: ${DEF_COLOR}"
printf "${MAGENTA}Idris4work\t\n${DEF_COLOR}"
printf "${BLUE}\n-------------------------------------------------------------------------\n${DEF_COLOR}"

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

# Test cases based on the provided list
run_test "a" ERROR
run_test "111a11" ERROR
run_test "hello world" ERROR
run_test "" ERROR
run_test "0 0" ERROR
run_test "-01 -001" ERROR
run_test "111-1 2 -3" ERROR
run_test "-3 -2 -2" ERROR
run_test "\\n" ERROR
run_test "-2147483649" ERROR
run_test "-2147483650" ERROR
run_test "2147483648" ERROR
run_test "8 008 12" ERROR
run_test "10 -1 -2 -3 -4 -5 -6 90 99 10" ERROR
run_test "1 +1 -1" ERROR
run_test "3333-3333 1 4" ERROR
run_test "111a111 -4 3" ERROR
run_test "111111 -4 3 03" ERROR
run_test "2147483649" ERROR
run_test "2147483647+1" ERROR
run_test "0 1 2 3 4 5 0" ERROR
run_test "3 +3" ERROR
run_test "3+3" ERROR
run_test "42 42" ERROR
run_test "42 -42 -42" ERROR
run_test "4222-4222" ERROR
run_test "99999999999999999999999999" ERROR
run_test "-99999999999999999999999999" ERROR
run_test "0 -0 1 -1" ERROR
run_test "0 +0 1 -1" ERROR
run_test "111+111 -4 3" ERROR
run_test "-" ERROR

# Valid sorted case
run_test "1 2 3 4 5" OK
