#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinarySearchTree {
    public:
        Node* root;
    public:
        BinarySearchTree() {
            root = nullptr;
        }

        bool insert(int value) {
            Node* newNode = new Node(value);

            if (root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while (true)
            {
                if (newNode->value == temp->value) // where you have a node that you're trying to insert where that value is already in the tree.
                    return false;
                if (newNode->value < temp->value)
                {
                    if (temp->left == nullptr)
                    {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;

                }
                else // (newNode->value > temp->value)
                {
                    if (temp->right == nullptr)
                    {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }

        bool contains(int value)
        {    
            Node* temp = root;

            while(temp != nullptr) /* Condition is also check for root = nullptr */
            {
                if (value < temp->value)
                {
                    temp = temp->left;
                }
                else if (value > temp->value)
                {
                    temp = temp->right;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }
};

int main()
{
    BinarySearchTree* myBST = new BinarySearchTree();

/*
                            47
                    21              76
                18     *27*       52      82
 */

    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(52);
    myBST->insert(82);

    myBST->insert(27);

    cout << (myBST->root->left->right)->value << endl;
}
