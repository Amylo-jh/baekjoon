#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int k = 0;
    int p = 0;
    int max_frog = 0;

    for(int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if(ch == 'K')
        {
            k++;
            
            if(p > 0)
            {
                p--;
            }
        }
        else
        {
            p++;

            if(k > 0)
            {
                k--;
            }
        }

        max_frog = max(max_frog, k);
        max_frog = max(max_frog, p);
    }

    cout << max_frog;
}