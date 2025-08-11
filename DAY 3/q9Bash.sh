echo "Enter array of numbers : "
read -a num

echo "Enter index to remove : "
read index

num2=( )

k=0
l=${#num[*]}

while [[ $k -lt $l ]]
do
    if [[ $k -ne $index ]];
    then
        num2+=( ${num[$k]})
    fi
    (( k++ ))
done

echo "new array : ${num2[@]}"