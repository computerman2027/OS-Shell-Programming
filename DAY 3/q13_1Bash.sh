echo "Enter string : "
read str1
echo "Enter Sub string : "
read str2

l1=${#str1}
l2=${#str2}
flag=0

for (( i=0;i<l1;i++ ))
do
    str3=${str1:$i:$l2}
    if [[ $str3 == $str2 ]];
    then
        echo "Index no : $i "
        flag=$((flag+1))
    fi    
done

if [[ $flag -eq 0 ]]
then
    echo "Substring not present in main string"
fi