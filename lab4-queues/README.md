# My DSA Journey This Week: Queues

This week I learned about queues in C++. A queue follows **FIFO**: the first item added is the first item removed.

I practiced adding items with `enqueue()` and removing items with `dequeue()`. I also learned how to check if a queue is empty or full, and how to display its elements.

## What I learned

- How to build a queue using an array.
- How `front` and `rear` keep track of the queue.
- How to handle queue overflow and underflow.
- How a circular queue reuses empty spaces by wrapping around.
- How a double-ended queue can add and remove items from both sides.
- How pointers and dynamic arrays can be used to create a queue.
- How shifting elements changes the position of items in a queue.

## What I did in tasks 1-5

1. **Task 1:** I created a queue that removes the front item and shifts the remaining items to the left.
2. **Task 2:** I created a circular double-ended queue. It can insert and remove items from both the front and rear.
3. **Task 3:** I tested a normal queue, including removing from an empty queue and adding to a full queue.
4. **Task 4:** I added a function to count how many items are currently in the queue.
5. **Task 5:** I displayed the front and rear items and checked how they change after removing an item.

## My progress

By completing these tasks, I moved from learning the basic queue idea to using different queue designs. I now understand how queue positions change during insertion and deletion, and I can test special cases such as an empty or full queue.

One thing I still need to check in Task 1 is the left-shift statement. It should assign the next value to the current position, for example `list[i] = list[i + 1];`.
