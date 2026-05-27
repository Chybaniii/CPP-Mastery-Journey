# Problem 23 - Print First Letter of Each Word

## Description:
This program reads a full string from the user and prints the *first letter of each word* in the string.

## Concepts Used:
- Strings in C++
- For loop
- Boolean flag (isFirstLetter)
- Conditions (if statements)
- Character comparison

## Notes:
- I learned a new idea called *state tracking*
- Instead of splitting the strig into words, we track our position inside the string

### How it works:
- We go through the string character by charactr
- If we find a space ' ', it means a new word will start next
- We use a boolean variabel (isFirstLetter) to detect the first character of each word

## Example:

### Input: 
Hello how are you doing

### Output:
H 
h 
a
y
d