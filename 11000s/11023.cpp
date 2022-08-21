#include <iostream>

using namespace std;

int main()
{
    int num = 0;
    while(1)
    {
        int temp;
        cin >> temp;
        if(cin.eof())
        {
            break;
        }
        num += temp;
    }

    cout << num;
}