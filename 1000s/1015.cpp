#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <pair <int, int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    stable_sort(arr.begin(),arr.end());
    vector <int> answer(n);
    for(int i = 0; i < n; i++)
    {
        answer[arr[i].second] = i;
    }
    for(int i : answer)
    {
        cout << i << " ";
    }
}