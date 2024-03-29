#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node *next;
        Node *prev;

        Node(int value)
        {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList{
    private:
        Node *head;
        Node *tail;
        int length;

    public:
        DoublyLinkedList(int value)
        {
            Node *newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        void printList()
        {
            Node *temp = head;

            while(temp) {
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

        void append(int value)
        {
            Node *newNode = new Node(value);

            if (0 == length) {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        void deleteLast()
        {
            if (0 == length)
            {
                return;
            }
            Node *temp = tail;
            if (1 == length)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;
            length--;
        }

        void prepend(int value)
        {
            Node *newNode = new Node(value);
            if (0 == length) {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }

        void deleteFirst()
        {
            if (0 == length)
            {
                return;
            }
            Node *temp = head;
            if (1 == length)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            length--;
        }

        Node *get(int index) {
            if (index < 0 || index >= length) {
                return nullptr;
            }

            Node *temp = head;
            if (index < length/2)
            {
                for(int i = 0; i < index; i++)
                {
                    temp = temp->next;
                }
            }
            else
            {
                temp = tail;
                for(int i = 0; i < length-index-1; i++) // or for(int i = length-1; i > index; i--)
                {
                    temp = temp->prev;
                }
            }
            return temp;
        }
        
        bool set(int index, int value)
        {
            Node* temp = get(index);
            if(temp)
            {
                temp->value = value;
                return true;
            }
            return false;
        }

        bool insert(int index, int value)
        {
            if(index < 0 || index > length)    return false;
        
            if(index == 0)
            {
                prepend(value);
                return true;
            }
        
            if(index == length)
            {
                append(value);
                return true;
            }
        
            Node *newNode = new Node(value);
            Node *before = get(index - 1);
            Node *after = before->next;
            
            newNode->next = after;
            newNode->prev = before;
            before->next = newNode;
            after->prev = newNode;
            length++;
            return true;
        }

        void deleteNode(int index)
        {
            if (index < 0 || index > length) return;
            if (index == 0)  return deleteFirst();
            if (index == length - 1) return deleteLast();

            Node *temp = get(index);
            Node *before = temp->prev;
            Node *after = temp->next;

            before->next = after;
            after->prev = before;

            delete temp;
            length--;
        }
};

int main()
{
    DoublyLinkedList* myDLL = new DoublyLinkedList(0);
    myDLL->append(1);
    myDLL->append(2);
    myDLL->append(3);
    myDLL->append(4);
    myDLL->append(5);
    myDLL->append(6);
    myDLL->append(7);

    cout << myDLL->get(4)->value;
    
    return 0;
}