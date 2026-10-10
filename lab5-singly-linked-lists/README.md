# DSA Journey This Week: Singly Linked Lists

This week I practiced implementing a singly linked list in C++ using object-oriented programming. I learned how nodes store data and links, how a list keeps track of its first node, and how insertion, deletion, traversal, and user interaction work together.

## Tasks Completed

### Task 1: Create a `Node` class

I created a `Node` class using OOP. Each node contains an integer `data` value and a `next` pointer. A constructor initializes the data and sets the next pointer to `NULL`.

### Task 2: Create a `singlylist` class

I created a `singlylist` class with a private `head` pointer. The constructor initializes `head` to `NULL`, which represents an empty linked list.

### Task 3: Insert at the head

I wrote `insertathead()` to create a new node and place it at the beginning of the list.

### Task 4: Insert at the end

I wrote `insertatend()` to traverse to the last node and attach a new node there. I also handled the empty-list case by making the new node the head.

### Task 5: Display the list

I wrote `display()` to traverse the complete list from `head` to `NULL` and print every node.

### Task 6: Delete from the head

I wrote `deleteathead()` to remove the first node, move `head` to the next node, and release the deleted node. The function also reports when the list is empty.

### Task 7: Delete from the end

I wrote `deleteatend()` and handled all three required cases:

- The list is empty.
- The list contains one node.
- The list contains multiple nodes.

### Task 8: Delete a specific value

I wrote `deletevalue(int val)` to search for a value and remove its node. The function handles deleting the head node, deleting a node in the middle or at the end, and displaying `Value not found` when the value does not exist.

### Task 9: Menu-driven linked-list program

I combined all operations into a complete menu-driven program. The user can insert at the head, insert at the end, delete from the head, delete from the end, delete a specific value, display the list, or exit the program.

## What I Learned

- How constructors initialize objects and pointers.
- How a private head pointer controls access to a linked list.
- How to insert and delete nodes without losing the rest of the list.
- How to handle empty lists and single-node lists safely.
- How to traverse a linked list using temporary pointers.
- How to organize linked-list operations in a reusable class.
- How to connect data-structure operations to a menu-driven program.