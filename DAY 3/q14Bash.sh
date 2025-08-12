echo "Enter first number : "
read num1

echo "Enter first number : "
read num2

while [[ $num1 -ne $num2 ]]
do
    if [[ $num1 -gt $num2 ]];
    then
        num1=$(( num1 - num2 ))
    elif [[ $num2 -gt $num1 ]];
    then
        num2=$(( num2 - num1 ))
    fi
done

echo "GCD : $num1 "