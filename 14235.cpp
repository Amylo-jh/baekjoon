#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    priority_queue<int> present;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if(a)
        {
            for(int j = 0; j < a; j++)
            {
                int charge;
                cin >> charge;
                present.push(charge);
            }
        }
        else
        {
            if(present.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << present.top() << "\n";
                present.pop();
            }
        }
    }
}