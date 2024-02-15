#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        vector <int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        long long answer = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                answer = answer + gcd(arr[i], arr[j]);
            }
        }
        cout << answer << "\n";
    }
}