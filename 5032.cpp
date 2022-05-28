#include <iostream>

using namespace std;

int main()
{
    int empty_bottle;
    int new_bottle;
    int require_bottle;
    int total_ate_bottle = 0;

    cin >> empty_bottle >> new_bottle >> require_bottle;


    empty_bottle += new_bottle;
    new_bottle = 0;

    while(1)
    {
        new_bottle = empty_bottle / require_bottle;
        empty_bottle = empty_bottle - new_bottle * require_bottle;        
        total_ate_bottle += new_bottle;
        empty_bottle = empty_bottle + new_bottle;

        if(new_bottle == 0)
        {
            break;
        }

        new_bottle = 0;
    }

    cout << total_ate_bottle;
}