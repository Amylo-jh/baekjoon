#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int gift, child;
    cin >> gift >> child;

    priority_queue <int> gifts;
    for(int i = 0; i < gift; i++)
    {
        int temp;
        cin >> temp;
        gifts.push(temp);
    }

    bool flag = true;
    for(int i = 0; i < child; i++)
    {
        int temp;
        cin >> temp;
        
        if(gifts.top() < temp)
        {
            flag = false;
            break;
        }
        else
        {
            gifts.push(gifts.top() - temp);
            gifts.pop();
        }
    }

    if(flag)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}