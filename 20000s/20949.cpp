#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <pair <int, int>> arr(n);
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i-1] = {-(a*a + b*b), i};
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++)
    {
        cout << arr[i].second << "\n";
    }
}