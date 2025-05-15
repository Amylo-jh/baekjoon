#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    while(q--)
    {
        int query, a, b;
        cin >> query >> a >> b;
        a--;
        b--;
        if(query == 1)
        {
            int count = 1;
            char ch = str[a];
            for(int i = a; i <= b; i++)
            {
                if(str[i] != ch)
                {
                    count++;
                    ch = str[i];
                }
            }
            cout << count << "\n";
        }
        else if(query == 2)
        {
            for(int i = a; i <= b; i++)
            {
                str[i] = str[i]+1;
                if(str[i] > 'Z')
                {
                    str[i] = 'A';
                }
            }
        }
    }
}