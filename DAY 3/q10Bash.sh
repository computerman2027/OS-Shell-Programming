echo "enter file name : "
read filename

if [[ ! -f "$filename" ]];
then
    echo "file not found" 
    exit 1
fi

echo "MENU : "
echo "1. Display contents of whole file"
echo "2. Display information of student by roll no"
echo "3. Delete information of student by roll no"
echo "4. Add new entry"
echo "5. Update an entry"
echo "6. Exit"

while true
do
    echo -e "\nEnter choice : "
    read ch

    case $ch in
        1)
            cat "$filename"
            ;;
        2)
            echo "Enter roll no "
            read rollno

            nooflines=$( grep "^$rollno |" $filename | wc -l )

            if [[ $nooflines -eq 1 ]];
            then
                grep "^$rollno |" $filename
            else
                echo "Error: Record not found"
            fi
            ;;

        3)
            echo "Enter roll no to delete "
            read rollno

            nooflines=$( grep "^$rollno |" $filename | wc -l )

            if [[ $nooflines -eq 1 ]];
            then
                grep -v "^$rollno |" "$filename" > temp.txt
                mv temp.txt "$filename"
                echo "Record with roll no $rollno deleted."
            else
                echo "Error: Record not found"
            fi
            ;;
        4)
            echo "Enter new roll number: "
            read newroll

            if grep -q "^$newroll |" "$filename"; then
                echo "Error: Roll number already exists."
            else
                echo "Enter name: "
                read newname
                echo "Enter city: "
                read newcity

                # Ensure file ends with a newline
                tail -c1 "$filename" | read -r _ || echo >> "$filename"

                # Now append safely
                echo "$newroll | $newname | $newcity" >> "$filename"

                {
                    head -n 1 "$filename"
                    tail -n +2 "$filename" | sort -n -k1,1
                } > temp.txt

                mv temp.txt "$filename"
                echo "New entry added and file sorted."
            fi
            ;;
        5)
            echo "Enter roll no to update: "
            read rollno

            if grep -q "^$rollno |" "$filename"; then
                echo "Enter new name: "
                read newname
                echo "Enter new city: "
                read newcity

                grep -v "^$rollno |" "$filename" > temp.txt
                mv temp.txt "$filename"

                # Ensure file ends with a newline
                tail -c1 "$filename" | read -r _ || echo >> "$filename"

                # Now append safely
                echo "$rollno | $newname | $newcity" >> "$filename"

                {
                    head -n 1 "$filename"
                    tail -n +2 "$filename" | sort -n -k1,1
                } > temp.txt
                mv temp.txt "$filename"

                echo "Record updated successfully."
            else
                echo "Error: Record not found."
            fi
            ;;

        6)
            echo "Exiting"
            exit 0
            ;;
        *)
            echo "INVALID OPTION"
    esac
done