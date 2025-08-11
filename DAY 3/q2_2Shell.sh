echo "Enter numbers separated by space: "
read -a numbers

if [[ ${#numbers[@]} -eq 0 ]]; then
    echo "ERROR: No input provided"
    exit 1
fi

sorted=($(printf "%s\n" "${numbers[@]}" | sort -n))
min=${sorted[0]}
max=${sorted[-1]}

echo "Max = $max"
echo "Min = $min"
