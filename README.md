*This project has been created as part of the 42 curriculum by stanaka2.*

## Project Name

### push_swap / checker

---

## Description

### push_swap

- **The main goal**
  - The goal is to sort the numbers in stack A in ascending order in as few operations as possible.
  - Output the sequence of operations required for sorting.
- **What the project does**
  - You have 2 stacks named **a** and **b**.
  - At the beginning:
    - The stack a contains a random number of unique negative and/or positive integers.
    - The stack b is empty.
  - You have the following operations:
    - **sa** (swap a): Swap the first 2 elements at the top of stack a.
 Do nothing if there is only one element or none.
    - **sb** (swap b): Swap the first 2 elements at the top of stack b.
 Do nothing if there is only one element or none.
    - **ss** : sa and sb at the same time.
    - **pa** (push a): Take the first element at the top of b and put it at the top of a.
 Do nothing if b is empty.
    - **pb** (push b): Take the first element at the top of a and put it at the top of b.
 Do nothing if a is empty.
    - **ra** (rotate a): Shift up all elements of stack a by 1.
 The first element becomes the last one.
    - **rb** (rotate b): Shift up all elements of stack b by 1.
 The first element becomes the last one.
    - **rr** : ra and rb at the same time.
    - **rra** (reverse rotate a): Shift down all elements of stack a by 1.
 The last element becomes the first one.
    - **rrb** (reverse rotate b): Shift down all elements of stack b by 1.
 The last element becomes the first one.
    - **rrr** : rra and rrb at the same time.

### checker

- **The main goal**
  - The goal is to check whether the sorting is completed using the operations entered from standard input.

---

## Instructions

### Compilation

``` bash
# push_swap
%> make
# checker
%> make bonus
```

### Run

``` bash
%> ./push_swap <numbers [INT_MIN - INT_MAX]>

# for example
%> ./push_swap 2 1 0
ra
sa

%> ./push_swap 42

%> ./push_swap 1 0 -3 42 2
ra
pb
pb
ra
ss
pa
pa
```

``` bash
%> ARG="<numbers [INT_MIN - INT_MAX]>"; ./push_swap $ARG | ./checker $ARG

# for example
%> ARG="2 1 0"; ./push_swap $ARG | ./checker $ARG
OK or KO
```

---

## Resources

- > [Xorshift](https://ja.wikipedia.org/wiki/Xorshift)
- > [乱数アルゴリズムXorshiftの弱点と改善案](https://qiita.com/Shinoda_Naoki/items/5208b295d633df0aab47)
- > [良い xorshift、悪い xorshift](https://www.cepstrum.co.jp/hobby/xorshift/xorshift.html)
- > [線形合同法](https://ja.wikipedia.org/wiki/%E7%B7%9A%E5%BD%A2%E5%90%88%E5%90%8C%E6%B3%95)

### AI

- AI was used for analyzing statistical data and for brainstorming.
- No AI-generated code or ideas were included in the project.

---

## My Benchmark

``` bash
%> python3 push_swap_tester.py -l 5 -c 120
Test 120 cases: arg_length=5 range=(-2147483638, 2147483647)
---- Result ----
max   : 8
median: 5
min   : 0
%> python3 push_swap_tester.py -l 100 -c 500
Test 500 cases: arg_length=100 range=(-2147483638, 2147483647)
---- Result ----
max   : 453
median: 424
min   : 389
%> python3 push_swap_tester.py -l 500 -c 500
Test 500 cases: arg_length=500 range=(-2147483638, 2147483647)
---- Result ----
max   : 3334
median: 3242
min   : 3137
```

Achieved the No.1 record at 42Tokyo as of December 7, 2025.

---

## Useful Tester and Visualizer

- Tester

> https://github.com/nafuka11/push_swap_tester.git

``` bash
# Bench test
python3 push_swap_tester.py -l 100 -c 500
python3 push_swap_tester.py -l 500 -c 500
```

- Visualizer
  
> https://github.com/o-reo/push_swap_visualizer.git

---

## SKILLS

<img src="https://img.shields.io/badge/--00599C.svg?logo=c&style=plastic" alt="C" height="30">

<img src="https://img.shields.io/badge/-Sorting%20Algorithm-ffffe0.svg?logo=&style=plastic" alt="sorting algorithm" height="30">

<br>
<br>

> <https://codesandbox.io/p/sandbox/t8csp?file=%2Fsrc%2FApp.vue%3A13%2C6>