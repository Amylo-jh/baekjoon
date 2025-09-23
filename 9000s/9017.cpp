#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct team
{
    int sum4 = 0;
    int sum5 = 0;
    int seq = 0;
    int t_num = 0;

    bool operator<(const team& other) const
    {
        if(sum4 != other.sum4)
        {
            return sum4 < other.sum4;
        }
        return sum5 < other.sum5;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        vector <int> arr(n);
        vector <int> finished(201);
        vector <team> info(201);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            finished[arr[i]]++;
        }
        int idx = 1;
        for(int i = 0; i < n; i++)
        {
            if(finished[arr[i]] == 6)
            {
                if(info[arr[i]].seq < 5)
                {
                    if(info[arr[i]].seq < 4)
                    {
                        info[arr[i]].sum4 += idx;
                    }
                    info[arr[i]].sum5 += idx;
                }
                info[arr[i]].seq++;
                idx++;
            }
        }
        for(int i = 1; i <= 200; i++)
        {
            info[i].t_num = i;
        }
        sort(info.begin(), info.end());
        for(auto i : info)
        {
            if(i.seq == 6)
            {
                cout << i.t_num << "\n";
                break;
            }
        }
    }
}