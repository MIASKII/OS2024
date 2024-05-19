#!/bin/bash


search_string="asd"
directory="./test"


output_file="found_files.txt"
> "$output_file"

for file in "$directory"/*.txt; do
    if grep -q "$search_string" "$file"; then
        echo "$file" >> "$output_file"
    fi
done

