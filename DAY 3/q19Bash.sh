# set -x

is_prime() {
    local n=$1
    local flag=0
    local i

    if [[ $n -eq 1 || $n -eq 0 ]];
    then
        flag=1
    fi 
    for (( i=2;i<n;i++ ))
    do
        if (( n % i == 0 ))
        then
            flag=1
            break
        fi
    done

    if [[ $flag -eq 0 ]];
    then
        echo -n "$n "
    fi
}


echo "Enter Lower bound : "
read le

echo "Enter Right bound : "
read ri

if [[ $le -gt $ri ]];
then
    echo "Error : left bound > right bound "
    exit 1
fi

for (( i=le;i<=ri;i++ ))
do
    # echo "$i"
    is_prime "$i"
done