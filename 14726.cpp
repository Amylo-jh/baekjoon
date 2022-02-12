#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int card[16];
    long long cardnum;

    for(int k = 0; k < t; k++)
    {
        cin >> cardnum;

        for(int i = 0; i < 16; i++)
        {
            int remainder = cardnum % 10;
            card[15-i] = remainder;
            cardnum = cardnum / 10;
        }

        for(int i = 0; i < 16; i = i + 2)
        {
            card[i] = card[i] * 2;

            if(card[i] >= 10)
            {
                int remainder = card[i] % 10;
                card[i] = card[i] / 10;
                card[i] = card[i] + remainder;
            }
        }

        int total = 0;
        for(int i = 0; i < 16; i++)
        {
            total = total + card[i];
        }

        if(total % 10 == 0)
        {
            cout << "T" << endl;
        }
        else
        {
            cout << "F" << endl;
        }
    }
}