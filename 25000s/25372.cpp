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

        if(6 <= str.length() && str.length() <= 9)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}