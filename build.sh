#!/bin/bash
ANTLR4_RUNTIME="/home/zhayongquan/runtime"
SRC="src"
GENERATED="grammar"

GPP_COMMAND="g++
    $SRC/*.cpp\
    $GENERATED/*.cpp \
    -I$SRC/*.h\
    -I$GENERATED\
    -L$ANTLR4_RUNTIME/run/usr/local/lib \
    -lantlr4-runtime \
    -I$ANTLR4_RUNTIME/runtime/src \
    -std=c++11 \
    -w \
    -g \
    -o main"
$GPP_COMMAND