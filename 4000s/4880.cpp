#include <iostream>

using namespace std;

int main()
{
    int num[3];

    while(1)
    {
        for(int i = 0; i < 3; i++)
        {
            cin >> num[i];
        }
        if(num[0] == 0 && num[1] == 0 && num[2] == 0)
        {
            break;
        }

        int diff1 = num[1] - num[0];
        int diff2 = num[2] - num[1];

        if(diff1 == diff2)
        {
            cout << "AP " << num[2] + diff2 << "\n";
        }
        else
        {
            cout << "GP " << num[2] * (diff2 / diff1) << "\n";
        }
    }
}