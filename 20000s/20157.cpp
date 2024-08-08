#include <iostream>
#include <map>
#include <numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int score = 0;
    map <pair <int, pair <int, int>>, int> mp;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        // y축 위에 있을 때
        if(a == 0)
        {
            if(b > 0)
            {
                mp[{1, {0, 1}}]++;
                score = max(score, mp[{1, {0, 1}}]);
            }
            else
            {
                mp[{-1, {0, 1}}]++;
                score = max(score, mp[{-1, {0, 1}}]);
            }
            continue;
        }

        // x축 위에 있을 때
        if(b == 0)
        {
            if(a > 0)
            {
                mp[{1, {1, 0}}]++;
                score = max(score, mp[{1, {1, 0}}]);
            }
            else
            {
                mp[{-1, {1, 0}}]++;
                score = max(score, mp[{-1, {1, 0}}]);
            }
            continue;
        }

        int g = gcd(a, b);
        int direction = b > 0 ? 1 : -1;
        a /= g;
        b /= g;

        mp[{direction, {a, b}}]++;
        score = max(score, mp[{direction, {a, b}}]);
    }

    cout << score;
}