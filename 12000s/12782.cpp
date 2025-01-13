#include <iostream>
#include <string>

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
        string a, b;
        cin >> a >> b;

        int zero = 0;
        int one = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i])
            {
                if(a[i] == '0')
                {
                    zero++;
                }
                else
                {
                    one++;
                }
            }
        }

        cout << max(zero, one) << '\n';
    }
}