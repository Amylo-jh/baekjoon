#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int comp(char a, char b)
{
    if(a == b)
    {
        return 1;
    }
    else if(a == 'S' && b == 'P')
    {
        return 2;
    }
    else if(a == 'P' && b == 'R')
    {
        return 2;
    }
    else if(a == 'R' && b == 'S')
    {
        return 2;
    }

    return 0;
}

int main()
{
    int n;
    string str;
    cin >> n >> str;

    int score = 0;
    int max_score = 0;
    int count;
    cin >> count;
    vector <string> arr(count);

    for(int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        vector <int> cnt(3);
        for(int j = 0; j < count; j++)
        {
            score += comp(str[i], arr[j][i]);

            if(arr[j][i] == 'S')
            {
                cnt[0]++;
            }
            else if(arr[j][i] == 'P')
            {
                cnt[1]++;
            }
            else if(arr[j][i] == 'R')
            {
                cnt[2]++;
            }
        }

        int r = cnt[2]*2 + cnt[1];
        int s = cnt[0]*2 + cnt[2];
        int p = cnt[1]*2 + cnt[0];

        max_score += max(r, max(s, p));
    }

    cout << score << '\n' << max_score;
}