isPrime(){
	c=0
	i=0
	for (( i=2; i<num/2; i++ ))
	do
    	if [ $((num%i)) == 0 ]; then
        	((c++))
    	fi
	done
	return $c
}

num=0
read -p "Enter a number : " max
if [ "$max" -le 1 ]; then
  echo "No prime numbers less than $max."
  exit 0
fi

echo "Prime numbers <"$max" :"




for (( num=2; num<=max; num++ ))
do
	isPrime $num
	if [ $? == 0 ]; then
    	echo $num
	fi
done
