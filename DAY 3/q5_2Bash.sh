if [[ $# -eq 0 ]];
then
    echo -e "No parameter provided: \nCorrect Usage = $0 arg1 arg2 arg3 ..."
    exit 1
fi

#print the output in one line using xargs
echo "$@" | tr " " "\n" | sort -nr | xargs