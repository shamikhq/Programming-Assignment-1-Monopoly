# Developer Log (DEVLOG.md)
## Monopoly Board Simulator (Spring 2026)

Minimum **6 entries** required.

Each entry must document learning and reasoning. Fabricated bugs are not expected.

---

## Allowed Entry Types
Each entry may be one of the following:

1) **Bug Fix Entry**
- The issue encountered.
- Error messages or symptoms.
- Attempts made.
- Final resolution.

2) **Edge Case / Testing Entry**
- A failure discovered through testing.
- The specific input/state that caused it.
- The change you made to handle it correctly.

3) **Engineering Decision Entry (up to 2 allowed)**
- A design decision you made.
- An alternative approach you considered.
- Why you chose one approach over another (tradeoffs).

---

### Entry 1
**Date:** 2026-04-05  
**Entry Type:** Bug Fix / Edge Case   
**Task worked on:** Core A  
**Issue or decision:** When the list is empty, I wasn't setting the tailNode=headNode.
**Error message / symptom (if applicable):** The code was crashing when I was initializing the linked list for the first time.
**What I tried:** I directly copied over the logic in the TODO and used print statements to test if it works properly.  
**Fix / resolution (or final decision):** It worked. 
**Commit(s):**  2026-04-05

---

### Entry 2
**Date:** 2026-04-05
**Entry Type:** Bug Fix
**Task worked on:** Code B
**Issue or decision:** My addMany method isn't stopping after it goes through all the values of the values vector.
**Error message / symptom (if applicable):** Prints out 40 (MAX_SPACES) regardless of what's in values.
**What I tried:** I tried to change the condition for the loop that iterates through spaces to stop once it reaches the length of values.
**Fix / resolution (or final decision):** I have to change the entire structure of the logic for the method, and now the correct number of spaces (based off values) is printed.
**Commit(s):** 2026-04-05


---

### Entry 3
**Date:** 2026-04-06  
**Entry Type:** Engineering Decision  
**Task worked on:** Core C 
**Issue or decision:** I decided to implement a for loop to effectively and efficiently implement the player moving along the board. 
**Error message / symptom (if applicable):** N/A
**What I tried:** I initially thought about doing a while loop, however, I realized I only need to check if the board is empty once.  
**Fix / resolution (or final decision):** By implementing a for loop that assumes that nodeCount is always right, I can effectively and safely move the player. 
**Commit(s):** I worked on Core C and D, testing and implementing both. 

---

### Entry 4
**Date:** 2026-04-06  
**Entry Type:** Bug Fix / Engineering Decision  
**Task worked on:** Core D
**Issue or decision:** I implemented Core D. 
**Error message / symptom (if applicable):** Initially, the board wasn't printing correctly. 
**What I tried:** Using the given playable traversal and the helper method countSpaces, I tested the Core D until I got it to work. 
**Fix / resolution (or final decision):** I had an infinite loop in my countSpaces method, and once I fixed that everything else aligned. 
**Commit(s):** I worked on Core C and D, testing and implementing both.

---

### Entry 5
**Date:** 2024-04-07  
**Entry Type:** Engineering Decision  
**Task worked on:** Advanced Option A
**Issue or decision:** I've decided to no longer do Advanced Option A, and instead do B because there is just too much to keep track of and too many edge cases.  
**Error message / symptom (if applicable):**  
**What I tried:**  I initially implemented a for loop to loop through the board and attack edge cases one by one, however, that was honestly just a pain. 
**Fix / resolution (or final decision):** By doing Option B, I'll be improving my understanding of pointers and memory allocation for a linked list. 
**Commit(s):** I'm no longer doing  Advanced Option A.

---

### Entry 6
**Date:** YYYY-MM-DD  
**Entry Type:** Bug Fix / Edge Case / Engineering Decision  
**Task worked on:**  
**Issue or decision:**  
**Error message / symptom (if applicable):**  
**What I tried:**  
**Fix / resolution (or final decision):**  
**Commit(s):**  
