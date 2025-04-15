#!/usr/bin/bash

echo "Enter the directory name:"
read dir

if [ -d "$dir" ]; then
    cd "$dir"
    ls > f
    exec < f

    while read line; do
        if [ -f "$line" ]; then
            if [ -r "$line" -a -w "$line" -a -x "$line" ]; then
                echo "$line has all permissions"
            else
                echo "$line file does not have all permissions"
            fi
        fi
    done
fi

-----------------------------------------------------------------------
#!/usr/bin/bash

read -p "Enter the directory name: " dir

if [ -d "$dir" ]; then
    echo "Checking files in '$dir'..."

    for file in "$dir"/*; do
        if [ -f "$file" ]; then
            if [ -r "$file" ] && [ -w "$file" ] && [ -x "$file" ]; then
                echo "$(basename "$file") has all permissions"
            else
                echo "$(basename "$file") does not have all permissions"
            fi
        fi
    done
else
    echo "Directory does not exist."
fi

