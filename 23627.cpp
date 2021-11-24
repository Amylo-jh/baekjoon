#include <iostream>
#include <string>

using namespace std;

int main()
{
    string driip = "driip";
    string test;
    int length;
    bool flag = false;

    cin >> test;
    length = test.length();

    char test1;
    char test2;

    if (length >= 5)
    {
        for (int i = 0; i < 5; i++)
        {
            test1 = test[length-i-1];
            test2 = driip[4-i];
            if(test[length-i-1] == driip[4-i])
                ;
            else
            {
                flag = true;
            }
        }
    }
    else
    {
        flag = true;
    }

    if(flag)
    {
        cout << "not cute";
    }
    else
    {
        cout << "cute";
    }
}