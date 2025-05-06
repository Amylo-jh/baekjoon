#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector <bool> arr(n+2);

    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp)
        {
            arr[i] = true;
            if(!arr[i-1])
            {
                answer++;
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a;
        if(a)
        {
            cin >> b;
            if(arr[b])
            {
                continue;
            }
            arr[b] = true;
            if(arr[b-1] && arr[b+1])
            {
                answer--;
            }
            else if(!arr[b-1] && !arr[b+1])
            {
                answer++;
            }
        }
        else
        {
            cout << answer << "\n";
        }
    }
}