# Lab Task 2 — C++ Fundamentals (Pre-DSA Revision)

This lab was done before starting the DSA course to revise core C++ concepts: arrays, pointers, and OOP basics.

## Tasks Covered

### 1. Array Input & Sum
Take array size from user, input elements, display them, and calculate the sum.

### 2. Fixed-Size Array in Reverse
Declare an array of size 8, take input via a for-loop, and display elements in reverse order.

### 3. Pointers — Basic Address Display
Use an int pointer and int variable, display both their addresses using `&`.

### 4. Pointers — User Input via Address
Take user input into an integer variable, then display it using the variable's address (dereferencing a pointer).

### 5. Pointer Arithmetic
Create a float array of 10 elements. Use pointer arithmetic (`*(ptr + i)`) to display elements at odd-numbered positions.

### 6. Car Class (OOP Basics)
Create a `Car` class with attributes `xPosition`, `yPosition`, `speed`.
Methods:
- `accelerate()` / `decelerate()` — change speed
- `moveForward()` / `moveBackwards()` — change xPosition
- `turnLeft()` / `turnRight()` — change yPosition
- `currState()` — display all data members
- `getX()` / `getY()` — getters (needed since attributes are private)

### 7. Array of Cars + Simulation
Create an array of 10 `Car` objects with random starting positions (using the parameterized constructor).
Run a loop of 100 iterations:
- Randomly select a car (`rand() % 10`)
- Randomly select a direction (`rand() % 4 + 1`) via `switch`
- Move the car (note: must call `accelerate()` for speed/position to actually change)
- Check every pair of cars for collision using the distance formula.