# Task 2
## Problem 1
file: t2_1.c
### functions: 
1) double my_abs(double op)
2) double newton_root(double num, double eps)
## Problem 2.1
file: t2_2_1.c
Horner method of calculating polynomial
## Problem 2.2
file: t2_2_2.c
Horner method of calculating derivative
## Problem 2.3
file: t2_2_3.c
Horner method of calculating antiderivative (integral)
## Problem 3
file: t2_3.c
### functions: 
1) long long iterativeFibonachi(int n)
2) long long recursiveFibonachi( int n)
### Time
The iterative method turned out to be many times faster than the recursive one.
Example:
```
Calculate 40'th of the Fibonacci sequence
Recursive way:	102334155	Time: 851146 	microsec
Iterative way: 	102334155	Time: 1 	microsec

Calculate 50'th of the Fibonacci sequence
Recursive way:	12586269025	Time: 79053670 	microsec
Iterative way: 	12586269025	Time: 1 	microsec
```
## Problem 4
file: t2_4.c
### functions: 
1) long long power(int a, int b)
2) double str2double (char str[STR_LEN])
### str2double
#### variables
1) int sign - ('+' = 1, '-' = -1)
2) int isMantissa - is caret after '.' flag
3) int isExponenta - is caret after 'E' flag
4) int isExponentaPositive - exponenta sign flag
5) double res - result
6) int mantissaCount - counter of numbers after '.'
7) int exponentaPower - counter of numbers after 'E'
#### function architecture
1) sign check
2) write numbers before '.'
3) skip '.'
4) write mantissa numbers before 'E'
5) skip E
6) exponenta sign check
7) write exponenta power
8) result ^ exponenta
9) return result with sign
