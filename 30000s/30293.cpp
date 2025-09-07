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
    vector <long long> arr(n+1);
    vector <long long> target(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> target[i];
    }
    long long count = 0;
    for(int i = 1; i <= n; i++)
    {
        if(arr[i] != target[i])
        {
            long long diff = target[i] - arr[i];
            count += abs(diff);
            for(int j = i; j <= n; j += i)
            {
                arr[j] += diff;
            }
        }
    }
    cout << count;
}