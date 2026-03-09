# CS210 Programming Assignment
## Monopoly Board Simulator (Spring 2026)

### Read Me
This project implements a 40 space Monopoly board game with many of the functionalities of the actual game, without being a complete simulation. 

**Build**: g++ -std=c++17 -Wall -Wextra -o board main.cpp

**Run**: ./board

### Data Structures Used
There are three essential data structures used for this project...

    MonopolySpace: representing a single space on a board. 
      - string propertyName: name of the space
      - string propertyColor: color of the space
      - int value: the hypothetical price of buying that space on the board 
      - int rent: the hypothetical price for landing on that space if you didn't own it
    
    Node<T>: a template for a singly linked node.
      - T data: stores a MonopolySpace
      - Node<T>* nextNode: points to the next node in the linked list

    Circular Singly Linked List: how the Monopoly board is implemented. 
    - *headNode: points to the start of the board
    - *tailNode: points to the last node of the board
    - *playerNode: points to where the player is on the board
    - int nodeCount: keeps track of how Monopoly spaces are in the board
    - int passGoCount: keeps track of how many times the player passed "GO" (headNode)

### Core Requirements
There are four main core requirements...

    Core A: Add a Space with Capacity Enforcement
      addSpace(const Space& s) --> adds a single board space to the end of the list
        - adds a new node to the tail
        - maintains circular structure (tail links back to head)
        - enforces a hard maximum of 40 nodes
        - returns success or failure when attempting to add beyond capacity

    Core B: Add Multiple Spaces at Once
      addMany(const vector<Space>& spaces) --> takes a collection of spaces and adds as many as possible
        - adds spaces sequentially
        - stops exactly when the board reaches capacity
        - returns the number of spaces successfully added
        - does not corrupt pointers if capacity is exceeded

    Core C: Traversal-Based Player Movement
      move(int steps) --> movement function for the player
      - moves the player pointer forward by n steps
      - correctly wraps around the board when passing the last node
      - detects and tracks when the player passes GO

    Core D: Controlled Board Display
      printBoard(int startIndex, int count) or printFromCurrent(int count)
      - prints a fixed number of spaces starting from a given position or the player’s current position

### Advanced Option
For my advanced option, I choose to implement Option B...

      Mirror the Board (Circular List Reversal)
      - reverses the next links of all nodes
      - preserves circular structure (the list must still loop correctly)
      - correctly handles:
        - empty board
        - single-node board
      - the player cursor must remain on the same logical space after reversal

### Traversal and Movement Logic
  
    Forward Traversal: the circular nature of the board doesn't allow for nullptrs. 
      - the board will automatically wrap around when tailNode -> nextNode is implemented
      - the same will happen when playerNode -> nextNode is implemented, causing passGoCount to increase. 


        