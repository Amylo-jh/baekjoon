#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, s, p;
    cin >> n >> s >> p;
    vector <int> arr(p, -1);
    if(n == 0)
    {
        cout << 1;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int rank = 1;
    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > s)
        {
            rank = i+2;
            idx = i+1;
        }
        else
        {
            break;
        }
    }
    while(idx < p && arr[idx] == s)
    {
        idx++;
    }
    if(idx == p)
    {
        cout << -1;
    }
    else
    {
        cout << rank;
    }
}