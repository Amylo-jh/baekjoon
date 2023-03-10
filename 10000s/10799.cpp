#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int total_stick = 0;
    int stack_stick = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(' && str[i+1] == ')')
        {
            total_stick += stack_stick;
            i++;
        }
        else if(str[i] == '(')
        {
            stack_stick++;
        }
        else
        {
            stack_stick--;
            total_stick++;
        }
    }

    cout << total_stick;
}