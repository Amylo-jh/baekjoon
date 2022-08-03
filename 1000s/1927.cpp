#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue <int, vector<int>, greater<> > que;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(temp)
        {
            que.push(temp);
        }
        else
        {
            if(!que.empty())
            {
                temp = que.top();
                que.pop();
            }
            cout << temp << "\n";
        }
    }
}