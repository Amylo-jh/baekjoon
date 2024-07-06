#include <iostream>

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
        int s;
        cin >> s;

        if(s == 1)
        {
            cout << "#\n\n";
            continue;
        }
        if(s == 2)
        {
            cout << "##\n##\n\n";
            continue;
        }

        s -= 2;
        for(int i = 0; i < s+2; i++)
        {
            cout << "#";
        }
        cout << "\n";

        for(int i = 0; i < s; i++)
        {
            cout << "#";
            for(int j = 0; j < s; j++)
            {
                cout << "J";
            }
            cout << "#\n";
        }

        for(int i = 0; i < s+2; i++)
        {
            cout << "#";
        }

        cout << "\n\n";
    }
}