#!/bin/bash

echo "Enter first number: "
read a
echo "Enter second number: "
read b

echo "Choose operation"
echo "a = add"
echo "b = sub"
echo "c = mult"
echo "d = div"
read choice
case $choice in
a) echo "Addition : $((a+b))";;
b) echo "Subtraction : $((a-b)) ";;
c) echo "Multiplication : $((a*b))";;
d) echo "Division : $((a/b))";;
esac
