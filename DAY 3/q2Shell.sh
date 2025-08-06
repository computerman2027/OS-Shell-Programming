#!/bin/sh

# Palindrome check script (sh-compatible)

echo "Enter a string: \c"
read str

l=0
r=$(expr length "$str")
r=$(expr "$r" - 1)

is_palindrome=1

while [ "$l" -lt "$r" ]
do
    left_char=$(printf "%s" "$str" | cut -c $((l + 1)))
    right_char=$(printf "%s" "$str" | cut -c $((r + 1)))

    if [ "$left_char" != "$right_char" ]; then
        echo "Not Palindrome String"
        is_palindrome=0
        break
    fi

    l=$(expr "$l" + 1)
    r=$(expr "$r" - 1)
done

if [ "$is_palindrome" -eq 1 ]; then
    echo "Palindrome String"
fi
