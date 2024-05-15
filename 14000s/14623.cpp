#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    long long num1 = 0, num2 = 0;
    for(char c : str1)
    {
        num1 *= 2;
        num1 += c - '0';
    }
    for(char c : str2)
    {
        num2 *= 2;
        num2 += c - '0';
    }

    num1 = num1 * num2;
    stack <int> stk;
    while(num1)
    {
        stk.push(num1 % 2);
        num1 /= 2;
    }

    while(!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
}