# Push_swap

This project is about creating two programmes. One of them, named push_swap, takes integer arguments and gives an output with the list of specific operations, that sort the array.

The second progaramme is the checker, that takes integers as arguments and reads instructions from the standard input. If provided instructions sort the array, then "OK" is displayed, if the array is not sorted, then "KO" is displayed.

Valid arguments are integers, they should not repeat. Sorting is performed on two stacks. Available commands are the following:

* sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
* sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
* ss : sa and sb at the same time.
* pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.
* rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

Checker programme accepts "-v" flag for visualization.

Launch the programmes in sequence in the following way:
```
$ ARG="5 9 3 6 1"; ./push_swap $ARG | ./checker -v $ARG
```

![alt text](https://raw.githubusercontent.com/Klubenn/Push_swap/master/sample_visualization.gif)
