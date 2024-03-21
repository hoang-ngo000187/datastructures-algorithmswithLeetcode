#include <iostream>

#include <string>
#include <stack>

using std::string; // Allows the use of 'string' instead of 'std::string'
using std::stack; // Allows the use of 'stack' instead of 'std::stack'

string reverseString(const std::string& str);

string reverseString(const string& str) {
    stack<char> s;
    
    for(char x: str)
    {
        s.push(x);
    }
    string str1 = "";
    
    while(!s.empty())
    {
        str1 += s.top();
        s.pop();
    }
    
    return str1;
}

int main()
{
    string s = "abcde";
    string s_reverse = reverseString(s);

    std::cout << s_reverse;
    return 0;
}