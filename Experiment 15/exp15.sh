#!/bin/bash

echo "Enter the option: "
echo "a = print the date"
echo "b = List all files in the current directory"
read choice
case $choice in
a) date;;
b) ls;;
*) echo " Not a valid option"
esac
