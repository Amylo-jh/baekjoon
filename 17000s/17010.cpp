#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        string str;
        cin >> n >> str;
        for(int i = 0; i < n; i++)
        {
            cout << str;
        }
        cout << "\n";
    }
}