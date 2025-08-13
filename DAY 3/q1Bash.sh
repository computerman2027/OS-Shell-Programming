# this is bash version. not compatible with all shell 

echo "MENU\n1) Merge 2 files into another\n2) search a pattern from a file\nEnter your Choice : "

read ch

case $ch in
1) read -p "Enter first file name : " f1
    read -p "Enter Second file name : " f2
    read -p "Enter New file name : " fnew
    # echo "$f1 , $f2";;

    if [ -f "$f1" ] && [ -f "$f2" ]; then
        cat "$f1" "$f2" > "$fnew"
        echo "File merged successfully in $fnew"
    else
        echo "Error Occured"
    fi
    ;;

2) read -p "Enter file name : " fl
     read -p "Enter pattern : " p

     if [ -f "$fl" ]; then
        count=$(grep -o "$p" "$fl" | wc -l)
        echo "Pattern $p found $count times in $fl"
    else
        echo "Error : File not found"
    fi
    ;;

*) echo "INVALID CHOICE";;
esac