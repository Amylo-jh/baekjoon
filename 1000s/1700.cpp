#include <iostream>
#include <vector>

using namespace std;

vector <int> tap;
vector <int> order;

int find(int t)
{
    for(int i = 0; i < tap.size(); i++)
    {
        if(tap[i] == t)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    tap.resize(n);
    order.resize(k);
    for(int i = 0; i < k; i++)
    {
        cin >> order[i];
    }

    int count = 0;
    for(int i = 0; i < k; i++)
    {
        // 이미 꽂혀 있는지 확인
        int plugged = find(order[i]);
        if(plugged != -1)
        {
            continue;
        }
        
        // 빈 칸이 있는지 확인
        int index = find(0);
        if(index != -1)
        {
            tap[index] = order[i];
            continue;
        }

        // 빈 칸도 없을 때
        index = -1;
        int unplug = -1;
        for(int t = 0; t < n; t++)
        {
            int temp = 0;
            for(int plug = i+1; plug < k; plug++)
            {
                if(tap[t] == order[plug])
                {
                    break;
                }
                temp++;
            }

            if(index < temp)
            {
                index = temp;
                unplug = t;
            }
        }
        tap[unplug] = order[i];
        count++;       
    }

    cout << count;
}