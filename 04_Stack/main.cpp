#include <iostream>
using namespace std;

class Node
{
    public:
        int value;
        Node *next;

        Node(int value)
        {
            this->value = value;
            next = nullptr;
        }
};

class Stack
{
    private:
        Node *top; // equivalent of head in Linked List
        /* Because Stack, we will and and remove Node from the Top, so we needn't have Bottom */
        // Node *bottom; // equivalent of tail in Linked List
        int height;
    public:
        Stack(int value)
        {
            Node *newNode = new Node(value);
            top = newNode;
            height = 1;
        }

        void printStack()
        {
            Node *temp = top;
            while (temp)
            {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getTop()
        {
            cout << "Top: " << top->value << endl;
        }

        void getHeight()
        {
            cout << "Height: " << height << endl;
        }

        void push(int value)
        {
            Node *newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }

        int pop()
        {
            if (0 == height)    return INT_MIN;
            
            Node *temp = top;
            int poppedValue = top->value;
            top = top->next;
            delete temp;
            height--;

            return poppedValue;
        }
};

int main()
{ 
    Stack *myStack = new Stack(1);

    cout << "Popped value: " << myStack->pop();
    cout << "\n\nPopped value: " << myStack->pop();
    return 0;
}