#include <iostream>

#include <string>
#include <stack>

using std::string; // Allows the use of 'string' instead of 'std::string'
using std::stack; // Allows the use of 'stack' instead of 'std::stack'

bool isBalancedParentheses(const std::string& parentheses);

bool isBalancedParentheses(const string& parentheses) {
    stack<char> s;
    bool ret = true;
    int cnt = 0;
    for(char x: parentheses)
    {
        if (x == '(')
        {
            s.push(x);
            cnt += 1;
        }
        else
        {
            if(cnt == 0)
            {
                ret = false;
                break;
            }
            else
            {
                cnt--;
                s.pop();
            }
        }
    }
    if(cnt != 0)
        ret = false;
    return ret;
}


int main()
{
    string s = "()()())";
    bool output = isBalancedParentheses(s);

    std::cout << output;
    return 0;
}