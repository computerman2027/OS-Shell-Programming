echo "MENU\n1) Number of presently active users\n2) displaying desired number of lines from top of the file\n3) Updating access time of a given file to current time\nenter your choice : "

read choice

case $choice in
    1)
        n=`who | wc -l `
    2)
        echo "Enter file name : "
        read filename

        if [[ ! -f $filename ]];
        then 
            echo "Error : file not found "
            exit 1
        fi

        echo "enter no of lines : "
        read nooflines

        head -"$nooflines" "$filename"
    *)
        echo "INVALID INPUT"
esac 
