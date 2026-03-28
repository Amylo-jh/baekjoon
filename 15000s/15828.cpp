#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num, size = 0;
    cin >> n;
    queue <int> q;
    while(cin >> num)
    {
        if(num == -1)
        {
            break;
        }
        else if(num == 0)
        {
            q.pop();
            size--;
        }
        else
        {
            if(size < n)
            {
                q.push(num);
                size++;
            }
        }
    }
    if(q.empty())
    {
        cout << "empty";
    }
    else
    {
        while(!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
    }
}