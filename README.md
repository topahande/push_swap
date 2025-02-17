# push_swap

C program to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

At the beginning, the stack a contains a random amount of negative and/or positive numbers which cannot be duplicated. The stack b is empty.
To sort the numbers in ascending order into stack a, following operations can be used: 

sa (swap a): Swap the first 2 elements at the top of stack a. \
sb (swap b): Swap the first 2 elements at the top of stack b. \
ss: sa and sb at the same time. \
pa (push a): Take the first element at the top of b and put it at the top  of a. \
pb (push b): Take the first element at the top of a and put it at the top  of b. \
ra (rotate a): Shift up all elements of stack a by 1. (The first element becomes the last one). \
rb (rotate b): Shift up all elements of stack b by 1. (The first element becomes the last one). \
rr : ra and rb at the same time. \
rra (reverse rotate a): Shift down all elements of stack a by 1. (The last element becomes the first one). \
rrb (reverse rotate b): Shift down all elements of stack b by 1. (The last element becomes the first one). \
rrr: rra and rrb at the same time. 

To run:

``
make
``

Example: 

``
./push_swap 2 4 7 5 12 65 1 -3
``

To count the number of operations, run:

``
ARG="2 4 7 5 12 65 1 -3"; ./push_swap $ARG | wc -l
``
