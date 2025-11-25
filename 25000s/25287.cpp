#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--)
    {
        int n, tmp;
        cin >> n;
        vector <vector <int>> arr(2, vector <int>(n));
        vector <int> answer(n);
        for(int i = 0; i < n; i++)
        {
            cin >> tmp;
            arr[0][i] = tmp;
            arr[1][i] = n - tmp + 1;
        }
        answer[0] = min(arr[0][0], arr[1][0]);
        bool flag = true;
        for(int i = 1; i < n; i++)
        {
            arr[0][i] = (answer[i-1] <= arr[0][i] ? arr[0][i] : INT32_MAX);
            arr[1][i] = (answer[i-1] <= arr[1][i] ? arr[1][i] : INT32_MAX);
            answer[i] = min(arr[0][i], arr[1][i]);
            if(answer[i] == INT32_MAX)
            {
                cout << "NO\n";
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout << "YES\n";
        }
    }
}