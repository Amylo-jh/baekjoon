#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string str;
    cin >> n >> str;

    vector <int> alpha(26, 0);
    int hi = 0;
    int lo = 0;
    int curr_len = 0;
    int max_len = 0;
    int count = 0;

    while(hi < str.length())
    {
        if(alpha[str[hi] - 'a'] == 0)
        {
            alpha[str[hi] - 'a']++;
            count++;
            
            if(count > n)
            {
                while(count > n)
                {
                    alpha[str[lo] - 'a']--;
                    if(alpha[str[lo] - 'a'] == 0)
                    {
                        count--;
                    }
                    lo++;
                }
            }
        }
        else
        {
            alpha[str[hi] - 'a']++;
        }

        curr_len = hi - lo + 1;
        max_len = max(max_len, curr_len);
        hi++;
    }

    cout << max_len;
}