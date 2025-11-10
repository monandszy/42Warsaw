#!/bin/bash

make

chmod 777 ./push_swap
chmod 777 ./checker_linux

generate_unique_numbers() {
  local count=$1
  local min=$2
  local max=$3

  local range_size=$((max - min + 1))
  if (( count > range_size )); then
    echo "Error: Cannot generate $count unique numbers from a range of size $range_size." >&2
    return 1
  fi

  shuf -i "${min}-${max}" -n "${count}" | tr '\n' ' '
}

run_test() {
  local numbers=("$@")
  
  ./push_swap "${numbers[@]}" > out.txt
  local result
  result=$(./checker_linux "${numbers[@]}" < out.txt)

  if [ "$result" == "OK" ]; then
    wc -l < out.txt
    return 0
  else
    echo -e "\n--- FAILED ---" >&2
    echo "Input: ${numbers[*]}" >&2
    echo "Checker Result: $result" >&2
    # echo "Instructions Generated:" >&2
    # cat out.txt >&2
    return 1
  fi
}

highest_lines=0
lowest_lines=100000000000000000000
lines=0
total_runs=100
range=500

for i in $(seq 1 $total_runs)
do
  numbers_to_test=$(generate_unique_numbers $range 0 1000)
  lines=$(run_test $numbers_to_test) || true
  if [ $lines > 0 ]; then
    echo "OK. Operations: $lines"
    if (( lines > highest_lines )); then
      highest_lines=$lines
    fi
    if (( lines < lowest_lines )); then
      lowest_lines=$lines
    fi
  fi
done

rm -rf out.txt

echo "-------------------------------------------------------"
echo "Highest number of operations found: $highest_lines"
echo "Lowest number of operations found: $lowest_lines"
echo "-------------------------------------------------------"
