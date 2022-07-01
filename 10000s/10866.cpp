#include <iostream>
#include <string>
#include <deque>

using namespace std;

bool is_deque_size_zero(deque <int> &dq1)
{
    if(dq1.size() > 0)
    {
        return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    deque <int> dq;

    for(int i = 0; i < n; i++)
    {
        string temp;
        int num;

        cin >> temp;

        if(temp == "push_front")
        {
            cin >> num;
            dq.push_front(num);
        }
        else if(temp == "push_back")
        {
            cin >> num;
            dq.push_back(num);
        }
        else if(temp == "pop_front")
        {
            if(is_deque_size_zero(dq))
            {
                cout << -1 << endl;
            }
            else
            {
                cout << dq[0] << endl;
                dq.pop_front();
            }
        }
        else if(temp == "pop_back")
        {
            if(is_deque_size_zero(dq))
            {
                cout << -1 << endl;
            }
            else
            {
                num = dq.back();
                cout << num << endl;
                dq.pop_back();
            }
        }
        else if(temp == "size")
        {
            cout << dq.size() << endl;
        }
        else if(temp == "empty")
        {
            cout << is_deque_size_zero(dq) << endl;
        }
        else if(temp == "front")
        {
            if(is_deque_size_zero(dq))
            {
                cout << -1 << endl;
            }
            else
            {
                num = dq.front();
                cout << num << endl;
            }
            
        }
        else if(temp == "back")
        {
            if(is_deque_size_zero(dq))
            {
                cout << -1 << endl;
            }
            else
            {
                num = dq.back();
                cout << num << endl;
            }
        }
    }
}