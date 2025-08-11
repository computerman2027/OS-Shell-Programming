echo "Enter numbers separated by space : "
read -a numbers

echo "${numbers[@]}" | tr " " "\n" | sort -nr | xargs