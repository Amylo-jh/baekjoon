#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <int> sum = {0};
    int n, m;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        temp = temp + sum[i];
        sum.push_back(temp);
    }

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << "\n";
    }
}