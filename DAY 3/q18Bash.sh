echo "enter array of numbers : "
read -a numbers

l=${#numbers[@]}

for (( i=0;i<$l-1;i++ ))
do
	for (( j=0;j<$l-$i-1;j++ ))
	do
		if [[ ${numbers[$j]} -lt ${numbers[$(( j+1 ))]} ]];
		then
			temp=${numbers[$j]}
			numbers[$j]=${numbers[$(( j+1 )) ]}
			numbers[$(( j+1 ))]=$temp
		fi
	done
done

echo "sorted array : ${numbers[@]}"