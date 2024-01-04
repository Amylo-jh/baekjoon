#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector <int> arr(n+1);
    vector <int> sum(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i] = arr[i] + sum[i-1];
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << sum[b] - sum[a-1];
        cout << "\n";
    }
}