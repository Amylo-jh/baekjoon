#include <iostream>
#include <string>

using namespace std;

int main()
{
    int count = 1;
    for (int i = 0; i < 6; i++)
    {
        string str;
        cin >> str;
        if (str == "W")
        {
            count++;
        }
    }
    count = 4 - count / 2;
    if (count == 4)
    {
        count = -1;
    }
    cout << count;
}