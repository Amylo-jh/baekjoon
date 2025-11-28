#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, num, diff;
    string str;
    cin >> n;
    vector <pair <int, char>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> str >> num >> diff;
        arr[i].first = num;
        arr[i].second = str[diff-1];
        if(arr[i].second >= 'a')
        {
            arr[i].second -= 'a' - 'A';
        }
    }
    sort(arr.begin(), arr.end());
    for(auto i : arr)
    {
        cout << i.second;
    }
}