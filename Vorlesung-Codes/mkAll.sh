mkdir bin || {
    echo "removing old binaries"
    rm -rf bin
    mkdir bin
}
gcc -o ./bin/1_functionPointer ./src/1_functionPointer.c
gcc -o ./bin/2_calcYearAndDay ./src/2_calcYearAndDay.c