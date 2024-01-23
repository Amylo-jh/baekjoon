#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n);
    stack <int> stk;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int pos = 0;

    int counter = 1;
    while(counter <= n)
    {
        if(pos <= n && arr[pos] != counter)
        {
            if(!stk.empty() && stk.top() == counter)
            {
                counter++;
                stk.pop();
            }
            else
            {
                stk.push(arr[pos]);
                pos++;
            }
        }
        else
        {
            pos++;
            counter++;
        }

        if(pos == n && stk.empty())
        {
            break;
        }
    }

    if(stk.empty() && pos == n)
    {
        cout << "Nice";
    }
    else
    {
        cout << "Sad";
    }
}