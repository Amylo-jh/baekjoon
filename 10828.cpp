#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int command_count;
    vector <int> stack;
    string command;
    int operand;

    cin >> command_count;

    for(int i = 0; i < command_count; i++)
    {
        cin >> command;

        if(command == "push")
        {
            cin >> operand;
            stack.push_back(operand);
        }
        else if(command == "pop")
        {
            if(stack.size() == 0)
            {
                cout << -1 << endl;
                continue;
            }
            cout << stack.back() << endl;
            stack.pop_back();
        }
        else if(command == "size")
        {
            cout << stack.size() << endl;
        }
        else if(command == "empty")
        {
            if(stack.size() == 0)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if(command == "top")
        {
            if(stack.size() == 0)
            {
                cout << -1 << endl;
                continue;
            }
            cout << stack.back() << endl;
        }

    }

}