echo -n "Enter string: "
read str1
echo -n "Enter substring: "
read str2

if grep -ob "$str2" <<< "$str1"; then
    :
else
    echo "Substring not present in main string"
fi
