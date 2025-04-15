#!/usr/bin/bash

echo "Enter a word to be deleted:"
read word

echo "Enter file name:"
read fname

echo "Lines in $fname after deleting the word $word:"
grep -v "$word" "$fname"

--------------------------------------------------------------------
#!/usr/bin/bash

read -p "Enter a word to be deleted: " word
read -p "Enter file name: " fname

echo "Lines in $fname after deleting the word '$word':"
grep -v "$word" "$fname"
