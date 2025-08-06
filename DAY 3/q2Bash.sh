# this is bash version. not compatible with all shell 


read -p "enter String : " str

l=0
r=${#str}
r=$((r-1))

is_palindrome=1

while ((l<r)) 
do 
    if [ "${str:$l:1}" != "${str:$r:1}" ]; then
        echo "Not Palindrome String"
        is_palindrome=0
        break
    fi
    l=$((l+1))
    r=$((r-1))
done

if (( is_palindrome == 1 )); then
    echo "Palindrome String"
fi