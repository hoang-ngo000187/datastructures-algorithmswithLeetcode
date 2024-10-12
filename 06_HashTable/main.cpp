#include <iostream>

using namespace std;

class Node {
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable {
    private:
        /* Two lines below is to create data map address space */
        static const int SIZE = 7; // "static" means that we're going to store one of the number 7 in memory
        Node* dataMap[SIZE];

    public:
        void printTable() {
            for(int i = 0; i < SIZE; i++) {
                cout << i << ":" << endl;
                if(dataMap[i]) {
                    Node* temp = dataMap[i];
                    while (temp)
                    {
                        cout << "{" << temp->key << ", " << temp->value << "}" << endl;
                        temp = temp->next;
                    }
                }
            }
        }

        int hash(string key)
        {
            int hash = 0;
            for (int i = 0; i < key.length(); i++)
            {
                int asciiValue = int(key[i]);
                hash = (hash + asciiValue*23) % SIZE;
            }
            return hash;
        }

        void set(string key, int value)
        {
            int index = hash(key);
            Node* newNode = new Node(key, value);

            // determine that whether or not there are already nodes at the "index"
            if (dataMap[index] == nullptr)
            {
                dataMap[index] = newNode;
            }
            else
            {
                Node* temp = dataMap[index];
                while(temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        int get(string key)
        {
            int index = hash(key);

            Node* temp = dataMap[index];
            while(temp != nullptr)
            {
                if (temp->key == key)
                {
                    return temp->value;
                }
                temp = temp->next;
            }
            return 0;
        }
};

int main()
{
    HashTable* myHastTable = new HashTable();

    myHastTable->set("nails", 100);
    myHastTable->set("tile", 50);
    myHastTable->set("lumber", 80);
    
    myHastTable->set("bolts", 200);
    myHastTable->set("screws", 140);

    myHastTable->printTable();

    cout << "tile: " << myHastTable->get("tile") << endl;
    cout << "fox: " << myHastTable->get("fox") << endl;

    return 0;
}