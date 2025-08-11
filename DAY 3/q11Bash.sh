echo "Enter number : "
read num

l=${#num}

sum=0
copy=$num

while [[ $num -gt 0 ]]
do
    d=$(( num % 10 ))
    n=$(( d ** l ))
    sum=$(( sum + n))
    num=$(( num / 10))
done

if [[ $sum -eq $copy ]];
then
    echo "Armstrong number "
else
    echo "Not Armstrong number "
fi    
