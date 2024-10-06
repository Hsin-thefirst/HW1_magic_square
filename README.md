This is for addressing magic square problem. One is my answer and one is gpt-improved version (though I think gpt's is wrong, it did work for the judge system!)  
Problem Description:  

This assignment is to be completed independently. Collaboration with others is not permitted.  

You are given a square matrix where three numbers are missing.  

The goal is to fill in the missing numbers so that the sum of each row, each column, and both diagonals is equal.  

The matrix size is n×n, where 2 < n < 10, and the missing numbers are denoted by underscores (‘_’).  

You are allowed to fill in exactly 3 missing values, and all numbers (both existing and to-be-filled) must be between 0 and 100 (inclusive).  

Each number in the matrix must be unique.  

If it's not possible to fill the matrix in a way that satisfies the magic square conditions, you should returnNo solution.  

Constraints  

The size of the matrix n × n is between 2 and 10.  
There are exactly 3 missing values (‘_’), and they must be filled with integers between 0 and 100 (inclusive).  
The sum of each row, column, and both diagonals is equal.  
All numbers in the final matrix must be unique.  

Input  

The first input line contains an integer n (2 ≤ n ≤ 10), representing the size of thematrix.  
The next n lines each contain n space-separated integers or underscores (‘_’),representing the matrix.  
– Integers represent the existing numbers in the matrix, which are unique and withinthe range [0, 100].  

– An underscore (‘_’) represents a missing number that you need to fill.  

  
Output  

If a solution exists, output the completed matrix, with each row printed as aspace-separated line of integers.  
If no solution exists, output “No solution”  
  
Sample Input 1   
  
3  
8 _ 6  
_ 5 7  
4 9 _  
Sample Output 1  
  
8 1 6  
3 5 7  
4 9 2  
Sample Input 2   
  
4  
16 3 2 13  
5 _ _ 8  
9 6 _ 12  
4 15 14 1  
Sample Output 2  
  
16 3 2 13  
5 10 11 8  
9 6 7 12  
4 15 14 1  
Sample Input 3   
  
3  
2 _ 6  
_ 5 7  
4 9 _  
Sample Output 3  

No solution
