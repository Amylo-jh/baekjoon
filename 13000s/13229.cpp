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
    vector <int> sum(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }
    int tc;
    cin >> tc;
    while(tc--)
    {
        int a, b;
        cin >> a >> b;
        a++, b++;
        cout << sum[b] - sum[a-1] << "\n";
    }
}