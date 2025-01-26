#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; t++)
    {
        int n;
        cin >> n;
        deque <int> dq;
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            dq.push_back(temp);
        }

        int min_value = 0;
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if(dq.front() <= dq.back())
            {
                if(dq.front() >= min_value)
                {
                    min_value = dq.front();
                    count++;
                }
                dq.pop_front();
            }
            else
            {
                if(dq.back() >= min_value)
                {
                    min_value = dq.back();
                    count++;
                }
                dq.pop_back();
            }
        }

        cout << "Case #" << t << ": " << count << "\n";
    }
}