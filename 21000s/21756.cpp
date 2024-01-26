#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    queue <int> q1;
    queue <int> q2;
    for(int i = 1; i <= n; i++)
    {
        q1.push(i);
    }

    bool erase = true;
    while(q1.size() > 1 || !q2.empty())
    {
        if(erase)
        {
            q1.pop();
            erase = !erase;
        }
        else
        {
            q2.push(q1.front());
            q1.pop();
            erase = !erase;
        }

        if(q1.empty())
        {
            q1 = q2;
            q2 = {};
            erase = true;
        }
    }

    cout << q1.front();
}