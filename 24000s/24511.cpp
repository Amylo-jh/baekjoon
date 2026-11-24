#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    cin >> n;
    vector<int> arr(n), arr2(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (!arr[i])
        {
            q.push(arr2[i]);
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        q.push(tmp);
        tmp = q.front();
        q.pop();
        cout << tmp << " ";
    }
}