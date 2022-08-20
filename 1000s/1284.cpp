#include <iostream>

using namespace std;

int main()
{
    while(1)
    {
        int num = 0;
        cin >> num;
        if(num == 0)
        {
            break;
        }

        int length = 1;

        while(num)
        {
            int temp = num % 10;
            num = num / 10;

            if(temp == 1)
            {
                length += 2;
            }
            else if(temp == 0)
            {
                length += 4;
            }
            else
            {
                length += 3;
            }

            length++;
        }

        cout << length << endl;
    }
}