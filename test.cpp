#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main()
{
    ListNode *head;
    int a[4] = {1,2,2,1};

    ListNode* temp = head;

    for (int i = 0; i < 4; i++)
    {
        ListNode* newNode;
        temp->val = a[i];
        temp->next = newNode;
        temp = newNode;
    }



    return 0;
}