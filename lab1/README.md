# DSA Lab 1 — Arrays & Inheritance

Introductory lab for the Data Structures & Algorithms course, covering basic array operations and object-oriented inheritance in C++.

## Task 1 — Array Operations

A program that takes a user-sized array as input and computes:
- **Maximum element** (`maxArr`)
- **Minimum element** (`minArr`)
- **Sum of elements** (`sumArr`)
- **Average of elements** (`averageArr`)

Each operation is written as a separate function that takes the array and its size as parameters, then loops through to compute the result.

**Concepts covered:**
- Passing arrays to functions
- Dynamically-sized arrays (size taken from user input)
- Basic loop-based accumulation (sum/average)
- Comparison-based tracking (max/min)

> **Note:** There's a small bug in `sumArr` and `averageArr` — `sum =+ sum + arr[i];` should be `sum = sum + arr[i];` (or `sum += arr[i];`). The `=+` is being read as assign-then-unary-plus, not add-and-assign, though it still happens to work here since `sum + arr[i]` is computed first either way.

## Task 2 — Inheritance (OOP)

Demonstrates inheritance using an `Employee` base class and two derived classes.

**Class structure:**
- `Employee` (base class)
  - Protected members: `Name`, `Address`
  - Constructor to initialize name/address
  - `display()` — prints name and address

- `Salaried_Emp : public Employee`
  - Adds `monthly_salary`
  - `Calculate_salary()` — returns fixed monthly salary

- `Hourly_Emp : public Employee`
  - Adds `hourly_rate` and `hours_worked`
  - `Calculate_salary()` — returns `rate × hours`

**Concepts covered:**
- Base class vs derived class
- `protected` access specifier (accessible in derived classes, not outside)
- Constructor chaining (`: Employee(name, address)`) to call the base constructor
- Method overriding-style specialization (`Calculate_salary()` differs per derived class)
- Public inheritance (`class X : public Employee`)


## Key Concepts Revised
- Function parameters with arrays
- Basic algorithmic patterns (find max/min, accumulate sum)
- Classes and constructors
- Inheritance (`public` base classes)
- Access specifiers (`private`, `protected`, `public`)
- Constructor initialization lists