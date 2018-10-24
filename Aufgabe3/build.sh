RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'
bold=$(tput bold)
normal=$(tput sgr0)

mkdir bin || {
    echo -e "\n${CYAN}${bold}[build.sh]: Removing old binaries.${normal}${NC}\n"
    rm -rf bin
    mkdir bin
}

gcc -w ./src/main.c ./src/reader.c ./src/codeGenerator.c ./src/correlationCalculator.c -o ./bin/main
