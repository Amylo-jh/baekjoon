#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    queue <int> lion;
    int max_group = 9999999;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if(temp == 1)
        {
            lion.push(i);

            if(lion.size() == k)
            {
                max_group = min(max_group, lion.back() - lion.front() + 1);
                lion.pop();
            }
        }
    }

    if(max_group == 9999999)
    {
        cout << -1;
    }
    else
    {
        cout << max_group;
    }
}