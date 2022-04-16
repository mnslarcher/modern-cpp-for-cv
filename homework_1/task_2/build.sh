#!/usr/bin/env bash

RESULTS_DIR=./results
OBJ_DIR=$RESULTS_DIR/obj
BIN_DIR=$RESULTS_DIR/bin
LIB_DIR=$RESULTS_DIR/lib
MAIN_PATH=$BIN_DIR/main
LIBIPB_ARITHMETIC_PATH=$LIB_DIR/libipb_arithmetic.a
# Note: there can be no spaces before and after the = sign.

if [ -d $OBJ_DIR ]; then rm -r $OBJ_DIR; fi
if [ -d $MAIN_PATH ]; then rm $MAIN_PATH; fi
if [ -d $LIBIPB_ARITHMETIC_PATH ]; then rm $LIBIPB_ARITHMETIC_PATH; fi
# Note: there can be no spaces before and after "="
# Note: there must be spaces after "["" and before "]"
# -d FILE - True if the FILE exists and is a directory.

mkdir -p $OBJ_DIR
c++ -c src/main.cpp -I ./include/ -o $OBJ_DIR/main.o 
c++ -c src/subtract.cpp -I ./include/ -o $OBJ_DIR/subtract.o
c++ -c src/sum.cpp -I ./include/ -o $OBJ_DIR/sum.o 
# [...] the -c option says not to run the linker. Then the output
# consists of object files output by the assembler.
# You will also need to specify the compiler where to look for header files, 
# use the -I./include/ option for this purpose.
# -I dir
#     Add the directory dir to the list of directories to be searched for header files during preprocessing.
#     Directories specified with -I options are scanned in left-to-right order.

ar rcs $LIBIPB_ARITHMETIC_PATH $OBJ_DIR/subtract.o $OBJ_DIR/sum.o

c++ $OBJ_DIR/main.o -L $LIB_DIR -lipb_arithmetic -o $MAIN_PATH
