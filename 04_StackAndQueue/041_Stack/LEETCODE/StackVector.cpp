/*
Stack: Push for a Stack That Uses a Vector ( ** Interview Question)
In the Stack: Intro video we discussed how stacks are commonly implemented using a vector instead of a Linked List.

Write the push() method to add an item onto a stack that is implemented with a vector.

Input:
The function is a member of the Stack class, which has a private member stackVector, a vector<int> representing the stack.



Output:
The function should not return any value, but it should add the given value to the top of the stack.



Constraints:
The push() function should work correctly for stacks of any size, including empty stacks.

*/

/*
Stack: Pop for a Stack That Uses a Vector ( ** Interview Question)
Add a member function to the Stack class that we started in the last exercise called pop() that removes the top element from the stack if it is not empty.

Remember: This Stack implementation uses a vector instead of a Linked List.



Input:
The function is a member of the Stack class, which has a private member stackVector, a vector<int> representing the stack.



Output:
The function should not return any value, but it should remove the top element from the stack if it is not empty. If the stack is empty, the function should do nothing.



Constraints:
The pop() function should work correctly for stacks of any size, including empty stacks.
*/

#include <iostream>
#include <vector>

using namespace std;

class Stack {
    private:
        vector<int> stackVector;
    
    public:
        vector<int>& getStackVector() {
            return stackVector;
        }
    
        void printStack() {
            for (int i = stackVector.size() - 1; i >= 0; i--) {
                cout << stackVector[i] << endl;
            }
        }
    
        bool isEmpty() {
            return stackVector.size() == 0;
        }
    
        int peek() {
            if (isEmpty()) {
                return int();
            } else {
                return stackVector[stackVector.size() - 1];
            }
        }
    
        int size() {
            return stackVector.size();
        }
        
        void push(int value)
        {
            stackVector.push_back(value);
        }

        void pop()
        {
            if(stackVector.size() == 0)
                return;
            
            stackVector.pop_back();
        }
};


