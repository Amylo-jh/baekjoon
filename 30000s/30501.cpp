#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(char c : str)
        {
            if(c == 'S')
            {
                cout << str;
                break;
            }
        }
    }
}