#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <pair <int, string>> arr(n);
    for(int i = 0; i < n; i++)
    {
        string a, b;
        int value = 0;
        cin >> a >> b;
        if('0' <= a[0] && a[0] <= '9')
        {
            value = stoi(a);
            value /= 2;
        }
        else
        {
            value = stoi(b);
            b = a;
        }
        arr[i].first = value;
        arr[i].second = b;
    }

    sort(arr.begin(), arr.end());
    for(auto i : arr)
    {
        cout << i.second << "\n";
    }
}