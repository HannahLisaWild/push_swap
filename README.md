# push_swap

An algorithmic sorting project from the 42 curriculum. The goal is to sort a stack of integers using a limited set of operations and the fewest moves possible. The challenge is to implement an efficient sorting algorithm tailored to the constraints.

---

## 📌 Subject Summary

- Sort a stack of integers using **only allowed stack operations**.
- The program outputs the **sequence of operations** needed to sort.
- Performance is measured by the **number of operations** performed.
- Two stacks are used: **stack A** (initial input) and **stack B** (auxiliary).
- You also write a **checker** program to validate move sequences.

---

## 📦 How to Compile

```bash
make

This compiles the push_swap executable.

To clean:

make clean
make fclean

---

## 🚀 Usage
Running the sorter:

./push_swap 3 2 1

Output:

sa
rra

You can also provide inputs via quotes:

./push_swap "3 2 1"


## 📚 Allowed Instructions

Only these stack operations are permitted:

    sa, sb, ss – swap top elements

    pa, pb – push between stacks

    ra, rb, rr – rotate stack up

    rra, rrb, rrr – rotate stack down

## 🧠 Learning Outcomes

    Algorithm design under constraints

    Mastering stack-based data structures

    Optimizing for performance and minimal instructions

    Input parsing and error handling
