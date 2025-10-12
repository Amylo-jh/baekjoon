#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector <int> arr(n+1);
    vector <int> sum(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i-1] + abs(arr[i] - arr[i-1]);
    }
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a] << "\n";
    }
}