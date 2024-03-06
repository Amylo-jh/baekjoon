#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector <pair <int, int>> arr(n);
    for(int i = 0; i < n; i++)
    {

        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());

    int counter = 0;
    do
    {
        int delta = 0;
        bool is_success = true;
        for(int i = 0; i < n; i++)
        {
            delta += arr[i].first;
            delta -= k;

            if(delta < 0)
            {
                is_success = false;
                break;
            }
        }

        if(is_success)
        {
            counter++;
        }
    }
    while(next_permutation(arr.begin(), arr.end()));

    cout << counter;
}