RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'
bold=$(tput bold)
normal=$(tput sgr0)

mkdir bin || {
    echo -e "\n${CYAN}${bold}[build.sh]: Removing old binaries.${normal}${NC}\n"
    rm -rf bin
    echo -e "\n${CYAN}${bold}[build.sh]: Create folder for binaries.${normal}${NC}\n"
    mkdir bin
}

echo -e "\n${CYAN}${bold}[build.sh]: Build project.${normal}${NC}\n"
gcc -g ./src/main.c ./src/reader.c ./src/codeGenerator.c ./src/correlationCalculator.c -o ./bin/main
echo -e "\n${CYAN}${bold}[build.sh]: Successfully built project.${normal}${NC}\n"