#!/bin/bash

echo "For"
for i in 1 2 3 4 5
do
  echo $i
done

echo
echo

echo "Until"

i=1
until [ $i -gt 5 ]
do
  echo $i
  ((i++))
done

echo
echo

echo "While"

i=1
until [ $i -gt 5 ]
do
  echo $i
  ((i++))
done
