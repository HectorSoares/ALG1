EXEC=$1
TMP_OUT=$2

for i in {0..9..1}; do
  testname=$(printf "caso-teste0%01d" $i)
  $EXEC < tests/$testname-input.txt > $TMP_OUT
  if ! diff -qwB test/$testname-saida.txt $TMP_OUT &>/dev/null; then
    echo "Test $testname failed"
  else
    echo "Test $testname passed"
  fi
done
rm $TMP_OUT