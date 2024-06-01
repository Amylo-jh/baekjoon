#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <vector <int>> arr;
    arr.push_back({0, 0, 0});
    arr.push_back({0, 0, 1});
    arr.push_back({0, 1, 0});
    arr.push_back({0, 1, 1});
    arr.push_back({1, 0, 0});
    arr.push_back({1, 0, 1});
    arr.push_back({1, 1, 0});
    arr.push_back({1, 1, 1});

    int tc;
    cin >> tc;
    while(tc--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if(arr[a][0] == arr[b][0] && arr[b][0] == arr[c][0] && arr[c][0] == arr[d][0])
        {
            cout << "YES\n";
        }
        else if(arr[a][1] == arr[b][1] && arr[b][1] == arr[c][1] && arr[c][1] == arr[d][1])
        {
            cout << "YES\n";
        }
        else if(arr[a][2] == arr[b][2] && arr[b][2] == arr[c][2] && arr[c][2] == arr[d][2])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}