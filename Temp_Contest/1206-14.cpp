#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n+2);

    long long side = 0;
    long long up = n*2;
    long long inside = 0;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        side += arr[i];
    }

    side *= 2;
    for(int i = 0; i < n+1; i++)
    {
        long long diff = abs(arr[i] - arr[i+1]);
        inside += diff;
    }

    cout << side + up + inside;
}