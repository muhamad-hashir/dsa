# Lab 3: Stacks and Queues in C++ (DSA)

This repository contains C++ implementations of fundamental linear data structures (**Stacks**, **Queues**, and **Double-Ended Queues**) built using arrays, object-oriented classes, and pointer/index management as part of Data Structures and Algorithms coursework.

---

### 1. Practice Files (`queue.cpp`, `stack.cpp`)
* Exploratory scripts used to practice circular queue wraparound logic, pointer arithmetic, and heap/stack memory management.

### 2. Stack Implementation (`task1.cpp`)
* **Description:** Implements a fixed-size stack (capacity of 10) using an array.
* **Key Features:**
  * Standard `push()` and underflow/overflow safety checks.
  * A custom `display()` method that outputs the current value of the `top` pointer and prints all elements in true **LIFO (Last In, First Out)** order from top to bottom *without* popping or modifying the stack contents.

### 3. Fixed-Front Queue Implementation (`task2.cpp`)
* **Description:** Implements a linear queue where the `front` pointer is permanently locked at index `0`.
* **Key Features:**
  * Insertion (`insert`) adds elements at the `rear` and increments the rear pointer.
  * Deletion (`remove`) grabs the element at index `0` and triggers a **left-shift loop** to move all remaining elements down, decrementing the `rear` pointer accordingly.

### 4. Double-Ended Queue (Deque) Implementation (`task3.cpp`)
* **Description:** Implements a Deque with a capacity of 10 items supporting insertion and deletion from both ends.
* **Key Features:**
  * Operations: `insertRear()`, `insertFront()`, `removeRear()`, `removeFront()`, `isEmpty()`, and `isFull()`.
  * Fully supports **index wraparound** at both ends of the array.
  * Driven by an interactive menu loop matching lab output specifications.

---