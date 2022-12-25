#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int commands;
    queue <int> num_queue {};
    string command;
    int temp;

    cin >> commands;

    for(int i = 0; i < commands; i++)
    {
        cin >> command;

        if(command == "push")
        {
            cin >> temp;
            num_queue.push(temp);
        }
        else if(command == "pop")
        {
            if(num_queue.size() == 0)
            {
                cout << -1 << endl;
                continue;
            }
            temp = num_queue.front();
            cout << temp << endl;
            num_queue.pop();
        }
        else if(command == "size")
        {
            cout << num_queue.size() << endl;
        }
        else if(command == "empty")
        {
            if(num_queue.size() == 0)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if(command == "front")
        {
            if(num_queue.size() == 0)
            {
                cout << -1 << endl;
                continue;
            }
            cout << num_queue.front() << endl;
        }
        else if(command == "back")
        {
            if(num_queue.size() == 0)
            {
                cout << -1 << endl;
                continue;
            }
            cout << num_queue.back() << endl;
        }
    }
}