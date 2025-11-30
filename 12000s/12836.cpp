#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, query, o, p, x;
    cin >> n >> query;
    vector <long long> arr(n+1);
    while(query--)
    {
        cin >> o >> p >> x;
        if(o == 1)
        {
            arr[p] += x;
        }
        else
        {
            long long sum = 0;
            for(int i = p; i <= x; i++)
            {
                sum += arr[i];
            }
            cout << sum << "\n";
        }
    }
}