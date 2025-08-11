echo "Enter numbers separated by space : "

read -a numbers

if [[ ${#numbers} -eq 0 ]];
then
    echo "ERROR : No input provided"
    exit 1
fi

max=${numbers[0]}
min=${numbers[0]}

for i in ${numbers[*]}
do
    if [[ $i -gt max ]]; 
    then 
        max=$i
    fi
    if [[ $i -lt min ]]; 
    then 
        min=$i
    fi
done

echo -e "Max = $max \nMin = $min" 