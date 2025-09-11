#!/bin/bash
# Compile all ex1.c … ex6.c into executables with the same base name

for f in ex*.c; do
    exe="${f%.c}"      # remove .c extension
    echo "Compiling $f -> $exe"
    gcc "$f" -o "$exe"
done
