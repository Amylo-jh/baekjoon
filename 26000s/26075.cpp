#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int condition = 1;
    string s, t;
    cin >> n >> m >> s >> t;
    vector <int> pos_a;
    vector <int> pos_b;
    if(n < m)
    {
        condition = 0;
    }
    for(int i = 0; i < n+m; i++)
    {
        if(s[i] == condition + '0')
        {
            pos_a.push_back(i);
        }
    }
    for(int i = 0; i < n+m; i++)
    {
        if(t[i] == condition + '0')
        {
            pos_b.push_back(i);
        }
    }

    long long move_a = 0, move_b = 0;
    for(int i = 0; i < min(n, m); i++)
    {
        int diff = abs(pos_a[i] - pos_b[i]);
        move_a += diff/2;
        move_b += diff/2;
        if(diff % 2)
        {
            if(move_a < move_b)
            {
                move_a++;
            }
            else
            {
                move_b++;
            }
        }
    }

    cout << move_a*move_a + move_b*move_b;

}