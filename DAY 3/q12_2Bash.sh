echo "enter 3 numbers "
read -a numbers

l=${#numbers[*]}

if [[ $l -lt 3 ]];
then
    echo "INVALID NO OF TERMS"
    exit 1
fi

for (( i=0;i<l;i++ ))
do
    for (( j=0;j<l;j++ ))
    do
        for (( k=0;k<l;k++ ))
        do
            if [[ $i -ne $j && $i -ne $k && $j -ne $k ]];
            then
                echo "${numbers[i]} ${numbers[j]} ${numbers[k]}"
            fi
        done
    done
done