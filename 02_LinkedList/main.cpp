#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next;

        /* Constructor */
        Node(int mValue) { 
            this->value = mValue;
            this->next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        /* Constructor */
        LinkedList(int mValue) {
            /* When create a LinkedList, we will create the First node of the LinkedList */
            Node* newNode = new Node(mValue);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        
        /* Destructor */
        ~LinkedList() {
            Node* temp = head;
            while (nullptr != head)
            {
                head = head->next;
                delete temp;
                temp = head;
            }
            /* head, tail and length are deleted by "Default Destructor" */
        }

        void printList() {
            Node* temp = head;
            while(temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getHead() {
            cout << "Head: " << head->value << endl;
        }

        void getTail() {
            cout << "Tail: " << tail->value << endl;
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }

        void append(int mValue)
        {
            Node* newNode = new Node(mValue); // create a new Node

            // Check if current Linked List is null or not
            if (0 == length) // or we can check head == nullptr or tail == nullprt
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            
            // Increase the length
            length++;
        }

        void deleteLast()
        {
            /*Case 01: Linked List is empty */
            if (0 == length)    return;
            /*Case 02: Linked List has more than 2 Node   */
            Node* temp = head;
            Node* pre = head;

            while (nullptr != temp->next)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
            length--;
            if (0 == length)
            {
                head = nullptr;
                tail = nullptr;
            }
            delete temp;
        }
};

int main()
{
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);

    cout << "LL before deleteLast(): \n";
    myLinkedList->printList();

    myLinkedList->deleteLast();
    cout << "\n\nLL after frist deleteLast(): \n";
    myLinkedList->printList();

    myLinkedList->deleteLast();
    cout << "\n\nLL after second deleteLast(): \n";
    myLinkedList->printList();

    myLinkedList->deleteLast();
    cout << "\n\nLL after third deleteLast(): \n";
    myLinkedList->printList();

    return 0;
}

/*
Result

LL before deleteLast(): 
1
2


LL after frist deleteLast():
1


LL after second deleteLast():


LL after third deleteLast():


*/