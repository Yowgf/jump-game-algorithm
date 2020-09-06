# Input variables
STEM=$1
IN=.$2
OUT=.$3
NUM_TESTS=$4
# Temporary output file
TMP_OUT=temp$OUT


# Testing
for i in $(seq 1 $NUM_TESTS); do
	testin=$(printf $STEM$i$IN)
	testout=$(printf $STEM$i$OUT)
	echo $testin
	./tp1 ./testcases/$testin > $TMP_OUT
	if ! diff -qwB ./testcases/$testout $TMP_OUT &> /dev/null; then
		echo "Test $testin failed"
	else
		echo "Test $testin passed"
	fi
done;
rm $TMP_OUT
