#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n+1);
    map <int, bool> mp;

    arr[0] = 0;
    mp[0] = true;
    for(int i = 1; i <= n; i++)
    {
        int next_value = arr[i-1] - i;
        if(next_value < 0 || mp[next_value])
        {
            next_value = arr[i-1] + i;
        }

        arr[i] = next_value;
        mp[next_value] = true;
    }

    cout << arr[n];
}