# push_swap
## Project from Algorithms branch in school 42
### The goal of this project is write two programmes.

 * The push_swap programme:
That programme just take from argv Non-repetitive integer values,
and prints in the stdout operations which will sort the stack.
Challenge of this programme is to write a sort algorithm,
which will sort the stack using the lowest possible number of operations.

 * The checker programme:
Like push_swap takes Non-repetitive integer values.
Then reads from stdin operations which will sort the stack.
If stack at the end is sorted prints OK message otherwise KO.

 ### My sorting algorithm sorts:

 * **100** random numbers by **500-600** operations.

 * **500** random numbers by **4800-5200** operations.

## Operations
#### Swap
* **sa** : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
* **sb** : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
* **ss** : **sa** and **sb** at the same time.
#### Push
* **pa** : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* **pb** : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
#### Rotate
* **ra** : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* **rb** : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* **rr** : **ra** and **rb** at the same time.
#### Reverse Rotate
* **rra** : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
* **rrb** : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
* **rrr** : **rra** and **rrb** at the same time.

## Stack a and b
Her i have doubly linked list.

![](https://github.com/prippa/my-projects-media/blob/main/push_swap/FlashyNeglectedAnemone-size_restricted.png)

a and b as start and end pointer of list.

![](https://github.com/prippa/my-projects-media/blob/main/push_swap/ShamelessHugeIcterinewarbler-size_restricted.png)

## checker programme flags
 * **-v**    : Visualizes how the stack was sorted when we already have the entire list of operations.
 * **-d**    : Debug mode. A mode where you can sort the stack by yourself without using push_swap programme.
 * **-s**    : Shows the stacks size (work with -v or -d flag)
 * **-h**    : Shows the last five operations that have already been executed (work with -v or -d flag)
 * **-o**    : Shows the sum of operations that have already been executed (work with -v or -d flag)
 * **-t**    : Shows the operation counter (work with -v or -d flag)
 * **-help** : prints usage.

## Visualization mod of already sorted stack by push_swap programm.
```
A="17 11 25 1 7 13 4 21 2 10 18 12 3 9 6 5 24 14 20 19 23 15 22 8 16";
```
```
./push_swap $A | ./checker -v -h -o -s -t $A
```
![](https://github.com/prippa/my-projects-media/blob/main/push_swap/ClutteredRaggedAttwatersprairiechicken-size_restricted.gif)

## Debug mode. When you can sort stack by yourself using existing operations.
```
./checker -d -h -o -s -t 2 3 5 1 4
```
![](https://github.com/prippa/my-projects-media/blob/main/push_swap/ColorfulWildAustraliankestrel-size_restricted.gif)

[more info](https://github.com/prippa/push_swap/blob/master/push_swap.en.pdf)
