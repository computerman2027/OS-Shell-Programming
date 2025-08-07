echo "enter File name : "
read filename

echo "Enter starting line no : "
read startlineno

echo "No Of Lines to be displayed : "
read nooflines

if [ -f "$filename" ]; then
    endline=`expr $startlineno + $nooflines - 1`
    
    awk "NR >= $startlineno && NR <= $endline" "$filename"
    else
        echo "File not found"
    fi