#!/bin/sh

RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'
bold=$(tput bold)
normal=$(tput sgr0)

mkdir bin || {
    echo "${CYAN}${bold}[build.sh]: Removing old binaries.${normal}${NC}"
    rm -rf bin
    echo "${CYAN}${bold}[build.sh]: Create folder for binaries.${normal}${NC}"
    mkdir bin
}

echo "${CYAN}${bold}[build.sh]: Build project.${normal}${NC}"

if gcc -g ./src/main.c ./src/reader.c ./src/codeGenerator.c ./src/correlationCalculator.c ./src/signalDecoder.c -o ./bin/main; then
    echo "${GREEN}${bold}=================================================================${normal}${NC}"
    echo "${GREEN}${bold}[build.sh]: Successfully built project. Check for warnings above.${normal}${NC}"
    echo "${GREEN}${bold}=================================================================${normal}${NC}"
else 
    echo "${RED}${bold}=====================================================================================${normal}${NC}"
    echo "${RED}${bold}[build.sh]: Build failed because of errors. Please check for them in the lines above.${normal}${NC}"
    echo "${RED}${bold}=====================================================================================${normal}${NC}"
fi