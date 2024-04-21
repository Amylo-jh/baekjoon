#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 키, 같은 키를 가진 사람 수
    stack <pair <int, int>> stk;
    int n;
    int now = 0, cnt_same_height = 0;
    long long cnt_pair = 0;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> now;

        cnt_same_height = 1;
        while(!stk.empty() && stk.top().first < now)
        {
            cnt_pair += stk.top().second;
            stk.pop();
        }

        if(!stk.empty())
        {
            if(stk.top().first == now)
            {
                cnt_pair += stk.top().second;
                cnt_same_height = (stk.top().second + 1);
                if(stk.size() > 1)
                {
                    cnt_pair++;
                }
                stk.pop();
            }
            else
            {
                cnt_pair++;
            }
        }

        stk.push({now, cnt_same_height});
    }

    cout << cnt_pair;
}