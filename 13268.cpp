#include <iostream>

using namespace std;

int main()
{
    int run;
    
    cin >> run;

    run = run % 100;

    if(run == 0 || run == 10 || run == 30 || run == 60)
    {
        cout << "0";
    }
    else
    {
        if((1 <= run && run <= 15) || (25 <= run && run <= 35) ||(55 <= run && run <= 65) ||(95 <= run && run <= 99))
        {
            cout << "1";
        }
        else if((16 <= run && run <= 24) ||(36 <= run && run <= 40) ||(50 <= run && run <= 54) ||(66 <= run && run <= 70) ||(90 <= run && run <= 94))
        {
            cout << "2";
        }
        else if((41 <= run && run <= 49) ||(71 <= run && run <= 75) ||(85 <= run && run <= 89))
        {
            cout << "3";
        }
        else
        {
            cout << "4";
        }
    }
}