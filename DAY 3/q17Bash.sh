echo "Enter n : "
read n

a=-1
b=1
c=$(( a+b ))

until [[ $c -ge $n ]]
do
    echo -n "$c "
    a=$b
    b=$c
    c=$(( a+b ))
done