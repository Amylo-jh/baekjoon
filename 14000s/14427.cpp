#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    // num, seq;
    vector <pair <int, int>> arr(n+1);
    // num, index, seq;
    priority_queue <pair <pair <int, int>, int>> pq;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = {temp, 0};
        pq.push({{-temp, -i}, 0});
    }

    int q;
    cin >> q;
    for(int ii = 1; ii <= q; ii++)
    {
        int query, i, v;
        cin >> query;
        if(query == 1)
        {
            cin >> i >> v;
            arr[i] = {v, ii};
            pq.push({{-v, -i}, ii});
        }
        else
        {
            while(1)
            {
                int curr_index = -pq.top().first.second;
                int curr_seq = pq.top().second;

                if(arr[curr_index].second > curr_seq)
                {
                    pq.pop();
                }
                else
                {
                    break;
                }
            }

            cout << -pq.top().first.second << "\n";
        }
    }
}