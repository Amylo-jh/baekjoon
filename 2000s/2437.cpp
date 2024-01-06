#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector <int> weight(n);
    for(int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    sort(weight.begin(), weight.end());

    int sum = 1;
    for(int i = 0; i < n; i++)
    {
        if(sum < weight[i])
        {
            cout << sum;
            return 0;
        }
        else
        {
            sum += weight[i];
        }
    }
    cout << sum;
}