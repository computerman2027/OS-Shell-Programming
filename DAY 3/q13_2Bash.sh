echo -n "Enter string: "
read str1
echo -n "Enter substring: "
read str2

pos=0
found=0

while [[ $str1 == *"$str2"* ]]; do
    # Find index of match
    prefix="${str1%%"$str2"*}"
    idx=${#prefix}
    echo "Index no : $((pos + idx))"
    found=1
    # Move search start to after this match
    str1="${str1:$((idx + ${#str2}))}"
    pos=$((pos + idx + ${#str2}))
done

if [[ $found -eq 0 ]]; then
    echo "Substring not present in main string"
fi
