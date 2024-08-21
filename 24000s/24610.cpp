#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <int> arr(m);

    queue <pair <int, int>> q;
    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        q.push({temp, i});
    }

    while(n-- && !q.empty())
    {
        int num = q.front().first;
        int seq = q.front().second;
        q.pop();

        arr[seq]++;
        num--;

        if(num)
        {
            q.push({num, seq});
        }
    }

    for(int i = 0; i < m; i++)
    {
        cout << arr[i] << "\n";
    }
}