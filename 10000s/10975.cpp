#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    vector <int> sorted(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sorted[i] = arr[i];
    }
    sort(sorted.begin(), sorted.end());

    int deque_count = 0;
    vector <pair <int, int>> deque_list;

    for(int i = 0; i < n; i++)
    {
        int num = arr[i];
        int pos = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();

        bool is_found = false;
        for(pair <int, int> &dq : deque_list)
        {
            if(dq.first == pos)
            {
                dq.first--;
                is_found = true;
            }
            else if(dq.second == pos)
            {
                dq.second++;
                is_found = true;
            }
        }
        if(is_found == false)
        {
            deque_list.push_back({pos - 1, pos + 1});
            deque_count++;
        }
    }

    cout << deque_count;
}