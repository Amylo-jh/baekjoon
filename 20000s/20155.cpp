#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <int> market(m+1);

    int max_val = 0;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        market[temp]++;
        max_val = max(max_val, market[temp]);
    }

    cout << max_val;
}