#!/usr/bin/bash

echo "Enter a number:"
read n

i=1
fact=1

while [ $i -le $n ]; do
    fact=`expr $fact \* $i`
    i=`expr $i + 1`
done

echo "The factorial of $n is $fact"

---------------------------------------------------
#!/usr/bin/bash

echo "Enter a number:"
read n

fact=1
for ((i=1; i<=n; i++)); do
    fact=$((fact * i))
done

echo "The factorial of $n is $fact"
