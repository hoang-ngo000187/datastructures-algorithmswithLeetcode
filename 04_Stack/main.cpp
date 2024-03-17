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
};

int main()
{
    Stack *myStack = new Stack(4);

    myStack->getTop();
    myStack->getHeight();
    myStack->printStack();
    return 0;
}