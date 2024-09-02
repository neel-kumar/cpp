#!/bin/bash

FILE=$1

echo "Processing file: $FILE"

rm -f a.out
g++ ${FILE}

if [[ -e "a.out" ]]; then
  echo "Compile success"
  ./a.out < in.txt > testo.txt

  echo ""
  echo "🐮--------------------------TEST/COMP------------------------🙏"
  if diff -w -y "testo.txt" "o.txt"; then
	echo "WORKS😎"
  else
  	echo ""
	echo "shit...🐒"
	cat in.txt
  fi
else
	echo "Compile failed"
fi
