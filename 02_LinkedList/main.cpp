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
            if (1 == length)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                Node* pre = head;
                while (nullptr != temp->next)
                {
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre;
                tail->next = nullptr;
            }
            delete temp;
            length--;
        }

        void prepend(int mValue)
        {
            Node* newNode = new Node(mValue);

            if(0 == length)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        void deleteFirst()
        {
            if(0 == length)     return;
            Node* temp = head;
            if(1 == length)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->next;
            }
            delete temp;
            length--;
        }

        Node* get(int mIndex)
        {
            if (mIndex < 0 || mIndex >= length)
            {
                return nullptr;
            }
            Node* temp = head;
            for(int i = 0; i < mIndex; i++)
            {
                temp = temp->next;
            }
            return temp;
        }

        bool set(int mIndex, int mValue)
        {
            Node* temp = get(mIndex);

            if (nullptr != temp)
            {
                temp->value = mValue;
                return true;
            }
            return false;
        }

        bool insert(int mIndex, int mValue)
        {
            if (mIndex < 0 || mIndex > length)
            {
                return false;
            }
            if (0 == mIndex)
            {
                prepend(mValue);
                return true;
            }
            if (mIndex == length)
            {
                append(mValue);
                return true;
            }
            
            Node* newNode = new Node(mValue);
            Node* temp = get(mIndex - 1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }

        void deleteNode(int mIndex)
        {
            if (mIndex < 0 || mIndex > length)
            {
                return; // can not delete
            }
            if (0 == mIndex)
            {
                return deleteFirst();
            }
            if (mIndex == length - 1)
            {
                return deleteLast();
            }

            Node* pre = get(mIndex - 1);
            Node* temp = pre->next; // Node in index = mIndex
            
            pre->next = temp->next;
            delete temp;
            length--;
        }
};

int main()
{
    LinkedList* myLinkedList = new LinkedList(0);
    myLinkedList->append(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);
    cout << "Before delete Node in index 3: \n";
    myLinkedList->printList();

    cout << "After delete Node in index 3: \n";
    myLinkedList->deleteNode(3);
    myLinkedList->printList();

    cout << "Delete the first Node\n";
    myLinkedList->deleteNode(0);
    myLinkedList->printList();

    cout << "Delete the last Node\n";
    myLinkedList->deleteNode(3);
    myLinkedList->printList();

    return 0;
}
