#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector <int> arr(n+1);
    for(int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    for(int i = 0; i < q; i++)
    {
        int s, e, m;
        cin >> s >> e >> m;

        vector <int> start;
        vector <int> end;
        for(int start = m; start <= e; start++)
        {
            end.push_back(arr[start]);
        }
        for(int end = s; end < m; end++)
        {
            start.push_back(arr[end]);
        }

        int idx = s;
        for(int num : end)
        {
            arr[idx++] = num;
        }
        for(int num : start)
        {
            arr[idx++] = num;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}