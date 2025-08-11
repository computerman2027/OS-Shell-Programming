echo "enter 3 numbers "
read -a numbers

l=${#numbers[*]}

if [[ $l -lt 3 ]];
then
    echo "INVALID NO OF TERMS"
    exit 1
fi

for i in "${numbers[@]}"
do
    for j in "${numbers[@]}"
    do
        for k in "${numbers[@]}"
        do
            echo "$i $j $k"
        done
    done
done