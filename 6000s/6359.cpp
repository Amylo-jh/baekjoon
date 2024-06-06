#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        cin >> n;

        vector <bool> arr(n+1, false);

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j*i <= n; j++)
            {
                arr[j*i] = !arr[j*i];
            }
        }

        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(arr[i])
            {
                cnt++;
            }
        }

        cout << cnt << '\n';
    }
}