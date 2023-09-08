#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector <int> arr1(n);
    vector <int> arr2(m);

    for(int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int counter1 = 1;
    int counter2 = 1;
    
    int time = arr1[0];
    for(int i = 0; i < n; i++)
    {
        if(arr1[i] >= time + 100)
        {
            counter1++;
            time = arr1[i];
        }
    }

    time = arr2[0];
    for(int i = 0; i < m; i++)
    {
        if(arr2[i] >= time + 360)
        {
            counter2++;
            time = arr2[i];
        }
    }

    cout << counter1 << " " << counter2;
}