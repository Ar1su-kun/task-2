# Task 3
### Usage:
``` shell
$ make
$ ./prog.out
```
Input: String o words and special words. Last string ends by `Ctrl + D`  
Output: The amount and list of all words. Sorted list of them.
## Modules
### list
files: list.c, list.h  
Works at the list level. Allocates memory for lists, fills, sorts and outputs them.
#### public functions
1) void initList(list \*lst);
2) void initBuffer(buffer \*buf);
3) void clearList(list \*lst);
4) void clearBuffer(buffer \*buf);
5) void addSymbol(buffer \*buf, int c);
6) void shrinkBuffer(buffer \*buf);
7) void shrinkList(list \*lst);
8) void addWord(list \*lst, buffer \*buf);
9) void printList(list \*lst);
10) void printSize(list \*lst);
11) void sortList(list \*lst);
### input
files: input.c, input.h  
#### public functions
1) Input(list \*lst);
#### how it works
![image](image.png)
### main
Use public functions of input and list modules 