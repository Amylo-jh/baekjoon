#include <iostream>
#include <unordered_map>

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
        unordered_map <long long, int> mp;
        int n;
        long long answer = 0;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            long long temp;
            cin >> temp;
            mp[temp]++;
            if(!answer && mp[temp] >= n/2+1)
            {
                answer = temp;
            }
        }
        if(answer == 0)
        {
            cout << "SYJKGW";
        }
        else
        {
            cout << answer;
        }
        cout << "\n";
    }
}