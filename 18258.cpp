#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    queue <int> qu;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string command;
        int num = 0;
        cin >> command;

        if(command == "push")
        {
            cin >> num;
            qu.push(num);
        }
        else if(command == "pop")
        {
            if(qu.size() == 0)
            {
                cout << -1 << "\n";
                continue;
            }
            else
            {
                cout << qu.front() << "\n";
                qu.pop();
            }
        }
        else if(command == "size")
        {
            cout << qu.size() << "\n";
        }
        else if(command == "empty")
        {
            bool is_queue_empty = false;
            if(qu.size() == 0)
            {
                is_queue_empty = true;
            }
            cout << is_queue_empty << "\n";
        }
        else if(command == "front")
        {
            if(qu.size() == 0)
            {
                cout << -1 << "\n";
                continue;
            }
            cout << qu.front() << "\n";
        }
        else if(command == "back")
        {
            if(qu.size() == 0)
            {
                cout << -1 << "\n";
                continue;
            }
            cout << qu.back() << "\n";
        }
    }
}