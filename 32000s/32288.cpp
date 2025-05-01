#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'I')
        {
            cout << "i";
        }
        else if(str[i] == 'l')
        {
            cout << "L";
        }
    }
}