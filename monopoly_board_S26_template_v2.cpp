#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

static const int MAX_SPACES = 40;

// -------------------------------
// Data class (NOT a struct)
// -------------------------------
class MonopolySpace {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    MonopolySpace() {
        propertyName = "";
        propertyColor = "";
        value = 0;
        rent = 0;
    }

    MonopolySpace(string propertyName, string propertyColor, int value, int rent): propertyName(propertyName), propertyColor(propertyColor), value(value), rent(rent) {
        // unlike the default constructor, this constructor assigns user specified values to a new space
    }

    bool isEqual(MonopolySpace other) {
        if(this->propertyName == other.propertyName) {
            return true;
        }
        return false;
    }

    void print() {
        cout << propertyName << " | " << propertyColor << " | $" << value << " | Rent " << rent << endl;
    }

    string getName() {
        return propertyName;
    }

    string getColor() {
        return propertyColor;
    }
};

// -------------------------------
// Template Node class (NOT a struct)
// -------------------------------
template <typename T>
class Node {
public:
    T data;
    Node<T>* nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

// -------------------------------
// Template Circular Linked List class
// Spring 2026 version: traversable board
// -------------------------------
template <typename T>
class CircularLinkedList {
private:
    Node<T>* headNode;
    Node<T>* tailNode;

    // player cursor for traversal-based gameplay
    Node<T>* playerNode;

    int nodeCount;
    int passGoCount;

public:
    CircularLinkedList() {
        headNode = nullptr;
        tailNode = nullptr;
        playerNode = nullptr;

        nodeCount = 0;
        passGoCount = 0;
    }

    // -------------------------------
    // Board Construction Policy (Reminder)
    // -------------------------------
    // Spaces are added during board construction BEFORE gameplay.
    // You choose how to construct the board:
    // - hardcode spaces, read from file, or generate programmatically
    // The only non-negotiable requirement:
    // - enforce MAX_SPACES
    // - maintain circular integrity
    // -------------------------------

    // -------------------------------
    // Core A: Add a Space with Capacity Enforcement
    // -------------------------------
    bool addSpace(T value) {
        if (nodeCount == MAX_SPACES) {
            return false;
        }
        if (nodeCount == 0) {
            headNode = tailNode = playerNode = new Node<T>(value);
            headNode->nextNode = headNode;
            //cout << "addSpace to empty list" << endl;
        }
        else {
            tailNode->nextNode = new Node<T>(value);
            tailNode = tailNode->nextNode;
            tailNode->nextNode = headNode;
            //cout << "addSpace!" << endl;
        }
        nodeCount++;
        return true;
    }

    // -------------------------------
    // Core B: Add Multiple Spaces at Once
    // -------------------------------
    int addMany(vector<T> values) {
        // TODO:
        // - Add sequentially until full
        // - Stop exactly when you reach MAX_SPACES
        // - Return number successfully added
        // - Do not corrupt pointers if capacity is exceeded
        int count;
        for (count = 0; count < values.size() && nodeCount < MAX_SPACES; count++) {
            if (!addSpace(values[count])) {
                break;
            };
        }
        return count;
    }

    // -------------------------------
    // Core C: Traversal-Based Player Movement
    // -------------------------------
    void movePlayer(int steps) {
        // TODO:
        // - Move playerNode forward 'steps' times, node-by-node
        // - Wrap naturally because list is circular
        // - Detect and track passing GO:
        //   increment passGoCount when a move crosses from tail back to head
        // - Must handle empty list safely
        if (nodeCount != 0) {
            for (int i =0; i < steps; i++) {
                playerNode = playerNode->nextNode;
                if (playerNode == headNode) {
                    passGoCount++;
                }
            }
        }
        cout << "movePlayer unwritten" << endl;
    }

    int getPassGoCount() {
        return passGoCount;
    }

    // -------------------------------
    // Core D: Controlled Board Display
    // -------------------------------
    void printFromPlayer(int count) {
        // TODO:
        // - Print exactly 'count' nodes starting from playerNode
        // - Must not infinite loop
        // - Must handle empty list
        // - Output must be deterministic and readable
        if (nodeCount != 0) {
            Node<T>* temp = playerNode;
            for (int i = 0; i < count; i++) {
                temp->data.print();
                if (temp->nextNode == headNode) {
                    break;
                }
                temp = temp -> nextNode;
            }
        }
    }

    // Optional helper: print full board once (one full cycle)
    void printBoardOnce() {
        // TODO:
        // - Traverse exactly one full cycle and print each node
        cout << "printBoardOnce unwritten" << endl;
    }

    // -------------------------------
    // Advanced Option A (Level 1): removeByName
    // -------------------------------
    bool removeByName(string name) {
        // TODO:
        // - Delete FIRST matching node
        // - Must handle:
        //   - deleting head
        //   - deleting tail
        //   - deleting the only-node list
        // - Maintain circular link tail->next=head
        // - If playerNode points to deleted node, move playerNode to a safe node
        // - nodeCount--
        if (headNode->data.getName() == name) {
            if (nodeCount == 1) {
                headNode = tailNode = playerNode = nullptr;
                nodeCount--;
                return true;
            }
            headNode = headNode->nextNode;
            nodeCount--;
            return true;
        }
        Node<T>* temp = headNode;
        for (int i = 0; i < nodeCount - 1; i++) {
            if (temp-> nextNode-> data.getName() == name) {
                temp-> nextNode = temp-> nextNode->nextNode;
                nodeCount--;
            }
        }
        return false;
    }

    // -------------------------------
    // Advanced Option A (Level 1): findByColor
    // -------------------------------
    vector<string> findByColor(string color) {
        // TODO:
        // - Traverse ring exactly once
        // - Collect matching names in vector<string>
        // - Return matches
        cout << "findByColor unwritten" << endl;
        vector<string> matches;
        return matches;
    }

    // -------------------------------
    // Advanced Option B (Level 2): Mirror the Board (Circular Reversal)
    // -------------------------------
    void mirrorBoard() {
        // TODO:
        // - Reverse the direction of the circular list by reversing next pointers
        // - Preserve circular structure
        // - Correctly handle empty list and single-node list
        // - Player cursor must remain on the same logical space after reversal
        cout << "mirrorBoard unwritten" << endl;
    }

    // -------------------------------
    // Edge-case helper: countSpaces O(n)
    // -------------------------------
    int countSpaces() {
        // TODO:
        int count = 1;
        Node<T>* temp = headNode;
        if (headNode == nullptr) {
            return 0;
        }
        while(temp->nextNode != headNode) {
            count++;
            temp = temp->nextNode;
        }
    }

    // -------------------------------
    // Cleanup
    // -------------------------------
    void clear() {
        // TODO:
        // - Safely delete all nodes
        // - Tip: if tailNode exists, break the cycle first: tailNode->nextNode = nullptr
        // - Then delete like a normal singly linked list
        cout << "clear unwritten" << endl;
    }
};

// -------------------------------
// Main: playable loop demo
// -------------------------------
int rollDice2to12() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    CircularLinkedList<MonopolySpace> board;

    // -------------------------------
    // Board Construction Phase
    // -------------------------------
    // You decide how to build the board:
    // - hardcode spaces, load from file, or generate spaces programmatically
    // The only requirement: never exceed MAX_SPACES and keep the list circular.
    //
    // Example (hardcoded) usage:
    // vector<MonopolySpace> spaces;
    // spaces.push_back(MonopolySpace("GO","None",0,0));
    // ...
    // board.addMany(spaces);
    //
    // NOTE: This starter calls addSpace once to show the intended API,
    // but your final submission should build a meaningful board.
    //board.addSpace(MonopolySpace("GO", "None", 0, 0));
    std::vector<MonopolySpace> values = {
        MonopolySpace("GO", "None", 0, 0),
    MonopolySpace("Mediterranean Avenue", "Brown", 60, 2),
    MonopolySpace("Community Chest", "None", 0, 0),
    MonopolySpace("Baltic Avenue", "Brown", 60, 4),
    MonopolySpace("Income Tax", "None", 200, 0),
    MonopolySpace("Reading Railroad", "Railroad", 200, 25),
    MonopolySpace("Oriental Avenue", "Light Blue", 100, 6),
    MonopolySpace("Chance", "None", 0, 0),
    MonopolySpace("Vermont Avenue", "Light Blue", 100, 6),
    MonopolySpace("Connecticut Avenue", "Light Blue", 120, 8),
    MonopolySpace("Jail", "None", 0, 0),
    MonopolySpace("St. Charles Place", "Pink", 140, 10),
    MonopolySpace("Electric Company", "Utility", 150, 0),
    MonopolySpace("States Avenue", "Pink", 140, 10),
    MonopolySpace("Virginia Avenue", "Pink", 160, 12),
    MonopolySpace("Pennsylvania Railroad", "Railroad", 200, 25),
    MonopolySpace("St. James Place", "Orange", 180, 14),
    MonopolySpace("Community Chest", "None", 0, 0),
    MonopolySpace("Tennessee Avenue", "Orange", 180, 14),
    MonopolySpace("New York Avenue", "Orange", 200, 16),
    MonopolySpace("Free Parking", "None", 0, 0),
    MonopolySpace("Kentucky Avenue", "Red", 220, 18),
    MonopolySpace("Chance", "None", 0, 0),
    MonopolySpace("Indiana Avenue", "Red", 220, 18),
    MonopolySpace("Illinois Avenue", "Red", 240, 20),
    MonopolySpace("B&O Railroad", "Railroad", 200, 25),
    MonopolySpace("Atlantic Avenue", "Yellow", 260, 22),
    MonopolySpace("Ventnor Avenue", "Yellow", 260, 22),
    MonopolySpace("Water Works", "Utility", 150, 0),
    MonopolySpace("Marvin Gardens", "Yellow", 280, 24),
    MonopolySpace("Go To Jail", "None", 0, 0),
    MonopolySpace("Pacific Avenue", "Green", 300, 26),
    MonopolySpace("North Carolina Avenue", "Green", 300, 26),
    MonopolySpace("Community Chest", "None", 0, 0),
    MonopolySpace("Pennsylvania Avenue", "Green", 320, 28),
    MonopolySpace("Short Line Railroad", "Railroad", 200, 25),
    MonopolySpace("Chance", "None", 0, 0),
    MonopolySpace("Park Place", "Dark Blue", 350, 35),
    MonopolySpace("Luxury Tax", "None", 100, 0),
    MonopolySpace("Boardwalk", "Dark Blue", 400, 50)
     };
    cout << board.addMany(values);

    // -------------------------------
    // Playable Traversal Loop
    // -------------------------------
    cout << "Spaces in board: " << board.countSpaces() << endl;
    for (int turn = 1; turn <= 10; turn++) {
        int roll = rollDice2to12();
        cout << "\nTurn " << turn << " | Rolled: " << roll << endl;
        board.movePlayer(roll);

        cout << "Board view from player (next 5 spaces):" << endl;
        board.printFromPlayer(5);

        cout << "Times passed GO so far: " << board.getPassGoCount() << endl;
    }

    // -------------------------------
    // Advanced Feature Demos (students choose path)
    // -------------------------------
    // Option A examples:
    // board.removeByName("Baltic Avenue");
    // vector<string> brownProps = board.findByColor("Brown");
    //
    // Option B example:
    // board.mirrorBoard();

    return 0;
}
