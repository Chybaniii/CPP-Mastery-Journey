# Problem 18 - Intersected Numbers in Matrices

## Description:
Fill two 3x3 matrices with hard-coded values and print them.

Check whether the matrices contain common numbers and print the result.

## Concepts Used:
- 2D arrays
- Nested for loops
- Functions

## Notes:
In this problem, I learned how to find the intersection between two matrices.

## Difference Between Solutions:

- In the first approach, I used a brute force method to find the intersection numbers between the two matrices.

- In the second approach, two functions are used:
  - IsNumberInMatrix: checks whether a number exists in a matrix or not.
  - PrintIntersectedNumbers: iterates through Matrix1 and uses IsNumberInMatrix to check if each number exists in Matrix2, then prints the common values.

This approach is more structured and easier to read compared to the first one.