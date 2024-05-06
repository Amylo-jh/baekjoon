#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector <vector <int>> arr(n+1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(a);
        arr[b].push_back(b);
    }

    for(int i = 1; i <= n; i++)
    {
        cout << arr[i].size() << "\n";
    }
}