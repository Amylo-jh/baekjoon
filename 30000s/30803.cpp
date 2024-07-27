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
    vector <int> arr(n);
    vector <bool> is_open(n, true);

    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << sum << '\n';
    int query;
    cin >> query;
    while(query--)
    {
        int x, valve, value;
        cin >> x;

        if(x == 1)
        {
            cin >> valve >> value;
            if(is_open[valve-1])
            {
                int diff = value - arr[valve-1];
                sum += diff;
                arr[valve-1] = value;
            }
            else
            {
                arr[valve-1] = value;
            }
        }
        else
        {
            cin >> valve;

            if(is_open[valve-1])
            {
                is_open[valve-1] = false;
                sum -= arr[valve-1];
            }
            else
            {
                is_open[valve-1] = true;
                sum += arr[valve-1];
            }
        }

        cout << sum << '\n';
    }
}