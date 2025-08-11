echo "Enter numbers separated by space : "
read -a numbers

printf "%s\n" "${numbers[@]}" | sort -nr | xargs