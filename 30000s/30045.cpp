#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        if(str.find("OI") != string::npos || str.find("01") != string::npos)
        {
            count++;
        }
    }

    cout << count;
}