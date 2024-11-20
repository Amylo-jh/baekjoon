#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> dice(n);
    vector <pair <int, int>> arr(101);
    for(int i = 0; i < n; i++)
    {
        cin >> dice[i];
        arr[dice[i]].first++;
        arr[dice[i]].second = i+1;
    }

    int idx = -1;
    for(int i = 100; i > 0 ; i--)
    {
        if(arr[i].first == 1)
        {
            idx = arr[i].second;
            break;
        }
    }

    if(idx > 0)
    {
        cout << idx;
    }
    else
    {
        cout << "none";
    }
}