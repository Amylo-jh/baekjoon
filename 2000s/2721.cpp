#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    vector <long long> arr(303);
    for(int i = 1; i <= 302; i++)
    {
        arr[i] = arr[i-1] + i;
    }
    while(tc--)
    {
        int n;
        cin >> n;

        long long sum = 0;
        for(int i = 1; i <= n; i++)
        {
            sum += arr[i+1]*i;
        }   
        cout << sum << '\n';
    }
}