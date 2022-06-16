#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int k = 0;
    int p = 0;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'K')
        {
            k++;
            
            if(p)
            {
                p--;
            }
        }
        else
        {
            p++;

            if(k)
            {
                k--;
            }
        }
    }

    cout << p + k;
}