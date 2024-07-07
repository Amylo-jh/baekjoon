#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    queue <pair <int, int>> q;
    vector <int> arr(n);

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        q.push({temp, i});
    }

    int time = 0;
    while(!q.empty())
    {
        int temp = q.front().first;
        int seq = q.front().second;
        q.pop();

        temp--;
        time++;
        if(temp == 0)
        {
            arr[seq] = time;
        }
        else
        {
            q.push({temp, seq});
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}