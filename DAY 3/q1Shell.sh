#!/bin/sh

# MENU for merging files or searching pattern
echo "MENU"
echo "1) Merge 2 files into another"
echo "2) Search a pattern from a file"
echo "Enter your Choice: \c"
read ch

case "$ch" in
1)
    echo "Enter first file name: \c"
    read f1
    echo "Enter second file name: \c"
    read f2
    echo "Enter new file name: \c"
    read fnew

    if [ -f "$f1" ] && [ -f "$f2" ]; then
        cat "$f1" "$f2" > "$fnew"
        echo "File merged successfully into $fnew"
    else
        echo "Error: One or both input files do not exist"
    fi
    ;;

2)
    echo "Enter file name: \c"
    read fl
    echo "Enter pattern: \c"
    read p

    if [ -f "$fl" ]; then
        count=`grep -o "$p" "$fl" | wc -l`
        echo "Pattern $p found $count times in $fl"
    else
        echo "Error: File not found"
    fi
    ;;

*)
    echo "INVALID CHOICE"
    ;;
esac
