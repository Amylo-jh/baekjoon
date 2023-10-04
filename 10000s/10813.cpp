#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <int> arr(n+1);
    for(int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}