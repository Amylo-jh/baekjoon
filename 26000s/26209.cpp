#include <iostream>

using namespace std;

int main()
{
    bool is_success = true;
    for(int i = 0; i < 8; i++)
    {
        int num;
        cin >> num;
        if(num > 1)
        {
            is_success = false;
            break;
        }
    }

    if(is_success)
    {
        cout << "S";
    }
    else
    {
        cout << "F";
    }
}