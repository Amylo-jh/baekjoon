#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <int> sequence;
    stack <pair<int, int>> tower;
    stack <pair<int, int>> que;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        pair <int, int> temp;
        cin >> temp.first;
        temp.second = i;
        tower.push(temp);
        sequence.push_back(0);
    }

    for(int i = n-1; i > 0; i--)
    {
        pair <int, int> temp = tower.top();
        que.push(temp);
        tower.pop();
        
        while(1)
        {
            if(!que.empty() && tower.top() >= que.top())
            {
                sequence[que.top().second] = tower.top().second + 1;
                que.pop();
            }
            else
            {
                break;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << sequence[i] << " "; 
    }
}