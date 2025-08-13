echo -n "Enter text: "
read str

totalCharacters=$(echo -n "$str" | wc -c)
noOfSpaces=$(echo "$str" | tr -cd ' ' | wc -c)
totalCharsWithoutSpace=$(( totalCharacters - noOfSpaces ))
totalWords=$(echo "$str" | wc -w)
noOfSpecialChars=$(echo "$str" | tr -cd '[:punct:]' | wc -c)

echo "total characters = $totalCharacters"
echo "total characters without space = $totalCharsWithoutSpace"
echo "total space = $noOfSpaces"
echo "total words = $totalWords"
echo "total special characters = $noOfSpecialChars"