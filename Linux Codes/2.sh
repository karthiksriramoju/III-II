#!/usr/bin/bash

echo "Enter file name:"
read f

echo "Enter starting position:"
read st

echo "Enter ending position:"
read end

echo "The lines between $st and $end from $f are:"

if [ $st -lt $end ]; then
    n1=`expr $st + 1`
    n2=`expr $end - 1`
    head -$n2 "$f" | tail +$n1
elif [ $st -gt $end ]; then
    n3=`expr $st - 1`
    n4=`expr $end + 1`
    head -$n3 "$f" | tail +$n4
fi

----------------------------------------------------------------------------
#!/usr/bin/bash

read  "Enter file name: " f
read  "Enter starting position: " st
read  "Enter ending position: " end

echo "The lines between $st and $end from $f are:"
sed -n "$st,$end p" "$f"

