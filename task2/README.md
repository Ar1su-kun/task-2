# Task2
## Problem 1
file: [t2_1.c](https://github.com/Ar1su-kun/CMC-LMSU-tasks-3rd-semester/blob/master/task2/t2_1.c)
### functions: 
1) double my_abs(double op)
2) double newton_root(double num, double eps)
## Problem 2.1
file: [t2_2_1.c](https://github.com/Ar1su-kun/CMC-LMSU-tasks-3rd-semester/blob/master/task2/t2_2_1.c)
Horner method of calculating polynomial
## Problem 2.2
file: [t2_2_2.c](https://github.com/Ar1su-kun/CMC-LMSU-tasks-3rd-semester/blob/master/task2/t2_2_2.c)
Horner method of calculating derivative
## Problem 2.3
file: [t2_2_3.c](https://github.com/Ar1su-kun/CMC-LMSU-tasks-3rd-semester/blob/master/task2/t2_2_3.c)
Horner method of calculating antiderivative (integral)
## Problem 3
file: [t2_3.c](https://github.com/Ar1su-kun/CMC-LMSU-tasks-3rd-semester/blob/master/task2/t2_3.c)
### functions: 
1) long long iterativeFibonachi(int n)
2) long long recursiveFibonachi( int n)
### Time
The iterative method turned out to be many times faster than the recursive one.
Example:
```
10
Iterative way: 	55	Time: 15 	microsec
Recursive way:	55	Time: 2 	microsec
30
Iterative way: 	832040	Time: 5 	microsec
Recursive way:	832040	Time: 7268 	microsec
50
Iterative way: 	12586269025	Time: 7 	microsec
Recursive way:	12586269025	Time: 76330920 	microsec
```
## Problem 4
file: [t2_4.c](https://github.com/Ar1su-kun/CMC-LMSU-tasks-3rd-semester/blob/master/task2/t2_4.c)
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
## Problem 5
file: [t2_5.c](https://github.com/Ar1su-kun/CMC-LMSU-tasks-3rd-semester/blob/master/task2/t2_5.c)
### structs
DynamicArray
	char* data  
	int size  
	int capacity  
node
    DynamicArray* data  
    struct node* next  
### functions
#### dynamic array functions
1) void initDA(DynamicArray \*arr, int capacity)
2) void appendDA(DynamicArray \*arr, char value)
3) void deleteDA(DynamicArray* arr)
4) void printDA(DynamicArray* arr)
#### singly linked list functions
1) void printDA(DynamicArray* arr)
2) void deleteL(node \*lst)
3) void printL(node \*lst)
4) void deleteSameAsLast(node \*\*lst)
### interface
input: A string of words separated by spaces
output: A singly linked list with words matching the last one deleted
## Problem 6
file: [t2_6.c](https://github.com/Ar1su-kun/CMC-LMSU-tasks-3rd-semester/blob/master/task2/t2_6.c)
### structs
tree
	int data
	tree \* left
	tree \* right
### functions
1) void insertToTree(tree\*\* root, int key)
2) tree\* prevMinInTree(tree* root)
3) void deleteFromTree(tree** root, int key)
4) void printTree(tree* root)
5) void freeTree(tree* root)
6) int searchInTree(tree* root, int key)
### interface
input:
	+num: add node to tree with key num
	-num: delete node from tree with key num
	?num: search for node with key num in tree and print 'yes' if it exists or 'no' if not 
## Problem 7
file: [t2_7.c](https://github.com/Ar1su-kun/CMC-LMSU-tasks-3rd-semester/blob/master/task2/t2_7.c)
New grammar:
```EBNF
<expr>::=<add>{+ <add>}{- <add>}
<add>::=<mult>{* <mult>}{/ <mult>}
<mult>::=<pow>|<pow> ^ <mult>
<pow>::=0|1|2|3|4|5|6|7|8|9|(<expr>)
```
### interface
input: expression
output: result of this expression
