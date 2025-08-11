echo "Enter numbers separated by space : "

read -a numbers

if [[ ${#numbers} -eq 0 ]];
then
    echo "ERROR : No input provided"
    exit 1
fi

l=${#numbers[@]}
i=0
j=0

while [[ $i -lt $((l-1)) ]]
do
    j=0
    while [[ $j -lt $((l-i-1)) ]]
    do
        if [[ ${numbers[j]} -gt ${numbers[$((j+1))]} ]];
        then
            (( numbers[j] = numbers[j] + numbers[j+1] ))
            (( numbers[j+1] = numbers[j] - numbers[j+1] ))
            (( numbers[j] = numbers[j] - numbers[j+1] ))

        fi
        ((j=j+1))
    done
    ((i=i+1))
done

echo "${numbers[@]}"