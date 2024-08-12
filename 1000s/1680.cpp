#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int cap, n;
        cin >> cap >> n;

        vector <pair <int, int>> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }

        int total_move = 0;
        int next_pos = 0;
        int curr_cap = 0;
        while(next_pos < n)
        {
            if(arr[next_pos].second + curr_cap <= cap)
            {
                curr_cap += arr[next_pos].second;
                arr[next_pos].second = 0;

                if(curr_cap == cap || next_pos == n-1)
                {
                    total_move += arr[next_pos].first * 2;
                    curr_cap = 0;
                }
                next_pos++;
            }
            else
            {
                total_move += (arr[next_pos].first * 2);
                curr_cap = 0;
            }
        }

        cout << total_move << "\n";
    }
}