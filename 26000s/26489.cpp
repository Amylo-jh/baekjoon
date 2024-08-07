#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int count = 0;

    while(cin >> str)
    {
        if(str == "gum")
        {
            count++;
        }
    }

    cout << count/2 << endl;
}