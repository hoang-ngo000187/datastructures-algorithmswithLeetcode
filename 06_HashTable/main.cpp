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
};

int main()
{
    HashTable* myHastTable = new HashTable();

    myHastTable->printTable();

    return 0;
}