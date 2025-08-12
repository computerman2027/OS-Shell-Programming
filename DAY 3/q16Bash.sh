echo "Enter nummber : "
read num

f=1

for (( i=1;i<=$num;i++ ))
do
    f=$(( f * i ))
done

echo "Factorial of $num is $f"