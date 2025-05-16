#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <pair <double, pair <int, int>>> arr;
    map <pair <int, int>, bool> mp;
    arr.push_back({0, {0, 1}});

    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            int g = gcd(i, j);
            int a = i/g;
            int b = j/g;
            if(!mp[{a, b}])
            {
                double value = double(a)/double(b);
                arr.push_back({value ,{a, b}});
                mp[{a, b}] = true;
            }
        }
    }

    sort(arr.begin(), arr.end());
    cout << arr.size() << "\n";
    for(auto i : arr)
    {
        cout << i.second.first << "/" << i.second.second << "\n";
    }
}