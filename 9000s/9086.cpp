#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        string str;
        cin >> str;

        cout << str[0] << str.substr(str.length()-1, 1) << endl;
    }
}