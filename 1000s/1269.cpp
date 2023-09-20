#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    map <int, int> arr;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[temp]++;
    }
    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        arr[temp]++;
    }

    int count = 0;
    for(auto i : arr)
    {
        if(i.second == 1)
        {
            count++;
        }
    }

    cout << count;
}