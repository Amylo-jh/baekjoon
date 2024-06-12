#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <int> arr(m);
    for(int i = 0 ; i < m; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());

    int max_value = 0;
    int cost = 0;
    for(int i = 0; i < min(n, m); i++)
    {
        if(max_value <= (i+1)*arr[i])
        {
            max_value = (i+1)*arr[i];
            cost = arr[i];
        }
    }

    cout << cost << " " << max_value << '\n';
}