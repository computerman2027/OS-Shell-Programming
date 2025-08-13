echo "Enter text : "
read str

str=$(echo "$str" | xargs )

str="$str "

totalCharacters=$(echo -n "$str" | wc -c )
noOfSpaces=$(echo "$str" | grep -o " " | wc -l )
totalCharsWithoutSpace=$(( totalCharacters - noOfSpaces ))
totalWords=$(echo "$str" | wc -w)
noOfSpecialChars=$(echo "$str" | grep -o "[^a-zA-Z0-9 ]" | wc -l)

echo "total characters = $totalCharacters"
echo "total characters without space = $totalCharsWithoutSpace"
echo "total space = $noOfSpaces"
echo "total words = $totalWords"
echo "total special characters = $noOfSpecialChars"