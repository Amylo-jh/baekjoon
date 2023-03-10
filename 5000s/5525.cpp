#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string s;
    cin >> n >> m >> s;

    int count = 0;
    for(int i = 0; i <= m - (n * 2 + 1); i++)
    {
        int k = 0;
        if(s[i] == 'I')
        {
            while(s[i+1] == 'O' && s[i+2] == 'I')
            {
                k++;
                if(k == n)
                {
                    count++;
                    k--;
                }
                i += 2;
            }
        }
    }

    cout << count;
}