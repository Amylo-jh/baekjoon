#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    vector <int> arr(n+1);
    for(int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(arr[i] - arr[i-1] > s)
        {
            cout << "BUG REPORT";
            return 0;
        }
    }
    cout << "POSSIBLE";
}