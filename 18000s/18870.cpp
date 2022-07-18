#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector <int> arr(n);
    vector <int> sorted(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sorted = arr;
    sort(sorted.begin(), sorted.end());

    vector <int>::iterator iter;
    iter = unique(sorted.begin(), sorted.end());

    sorted.erase(iter, sorted.end());

    for(int i = 0; i < n ; i++)
    {
        int position = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
        cout << position << " ";
    }
}