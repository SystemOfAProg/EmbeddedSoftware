RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'
bold=$(tput bold)
normal=$(tput sgr0)

mkdir bin || {
    echo -e "${CYAN}${bold}[build.sh]: Removing old binaries.${normal}${NC}"
    rm -rf bin
    mkdir bin
}
# Compile everything in 32 bit
{
    mkdir bin/32bit
    cd src
    for filename in *.c; do
        echo -e "${GREEN}${bold}[build.sh]: Compile $filename in 32bit.${normal}${NC}"
        gcc -m32 -o "../bin/32bit/${filename//.c/}" "$filename" || {
            echo -e "${RED}${bold}[build.sh]: Compilation of $filename in 32bit failed.${normal}${NC}"
        }
    done
    cd ./../
}
# Compile everything in 64 bit
{
    mkdir bin/64bit
    cd src
    for filename in *.c; do
        echo -e "${GREEN}${bold}[build.sh]: Compile $filename in 64bit.${normal}${NC}"
        gcc -m64 -o "../bin/64bit/${filename//.c/}" "$filename" || {
            echo -e "${RED}${bold}[build.sh]: Compilation of $filename in 64bit failed.${normal}${NC}"
        }
    done
    cd ./../
}
# Delete empty directories
[ "$(ls -A ./bin/32bit/)" ] || rm -rf "bin/32bit"
[ "$(ls -A ./bin/64bit/)" ] || rm -rf "bin/64bit"