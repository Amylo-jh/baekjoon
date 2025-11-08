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
    vector <int> arr(n+1);
    for(int i = 0; i < m; i++)
    {
        int c, a, b;
        cin >> c >> a >> b;
        if(arr[c] <= a)
        {
            arr[c] = b;
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}