#include <iostream>

using namespace std;

int main()
{
    int money;
    int money_2 = 0;
    int money_5 = 0;
    bool flag = false;

    cin >> money;

    while(money > 0)
    {
        if(money % 5 == 0)
        {
            money_5 = money / 5;
            flag = true;
            break;
        }
        else
        {
            money = money - 2;
            money_2++;
        }
    }

    if(money != 0 && flag == false)
    {
        cout << -1;
        return 0;
    }

    cout << money_2 + money_5;
}