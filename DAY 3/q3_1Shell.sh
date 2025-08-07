echo "enter File name : "
read filename

echo "Enter starting line no : "
read startlineno

echo "No Of Lines to be displayed : "
read nooflines

if [ -f "$filename" ]; then
    # Calculating total number of lines using expr
    endline=`expr $startlineno + $nooflines - 1`
    
    # Using head and tail to extract required lines
    head -n $endline "$filename" | tail -n $nooflines

    else
        echo "File not found"
    fi