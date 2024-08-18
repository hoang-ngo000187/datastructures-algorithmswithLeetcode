#include <iostream>
#include <stack>

using namespace std;

void sortStack(stack<int>& inputStack) {
    stack<int> tempStack;
    int temp1 = 0, temp2 = 0;

    temp1 = inputStack.top();
    inputStack.pop();
    tempStack.push(temp1);

    while (!inputStack.empty())
    {  
        temp1 = inputStack.top();
        inputStack.pop();

        temp2 = tempStack.top();
        
        if (temp1 <= temp2)
        {
            tempStack.push(temp1);
        }
        else
        {
            // return all element smaller than temp1 in tempStack
            while(temp2 < temp1)
            {
                tempStack.pop();
                inputStack.push(temp2);

                temp2 = tempStack.top();
            }
            tempStack.push(temp1);
        }
    }

    cout << "Hello";
}

int main()
{
    stack<int> a;
    a.push(7);
    a.push(1);
    a.push(100);
    a.push(6);

    sortStack(a);
    return 0;
}