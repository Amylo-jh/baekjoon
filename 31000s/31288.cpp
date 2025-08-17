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
        int n;
        string str;
        int remainder = 0;
        cin >> n >> str;
        for(int i = 0; i < str.length(); i++)
        {
            remainder += str[i] - '0';
            remainder %= 3;
        }

        if(n == 1)
        {
            cout << "4 2\n";
            continue;
        }

        for(int i = 0; i < n; i++)
        {
            string tmpstr = str;
            int num = str[i] - '0';
            if(num - remainder <= 0)
            {
                tmpstr[i] = num - remainder + 3 + '0';
            }
            else
            {
                tmpstr[i] = num - remainder + '0';
            }
            cout << tmpstr << " 3\n";
        }
    }
}