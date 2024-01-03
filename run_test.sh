#!/bin/bash
#chmod +x run_test.sh
#./run_test.sh input.txt expected_output.txt

# Check if the correct number of arguments is provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <input_file> <expected_output_file>"
    exit 1
fi

# Create a directory for test outputs if it doesn't exist
mkdir -p Tests

# Define file paths
input_file="$1"
expected_output_file="$2"
output_file="Tests/output.txt"

# Run the bsim executable with input from the input file and redirect output to output_file
./bsim < "$input_file" > "$output_file"

# Compare the output file with the expected output using the diff command
diff "$output_file" "$expected_output_file"

# Check the exit status of the diff command
if [ $? -eq 0 ]; then
    echo "Test passed: Output matches expected output."
else
    echo "Test failed: Output does not match expected output."
fi
