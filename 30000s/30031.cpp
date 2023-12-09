#include <iostream>

using namespace std;

int main()
{
    int n;
    int money = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a == 136)
        {
            money += 1000;
        }
        else if(a == 142)
        {
            money += 5000;
        }
        else if(a == 148)
        {
            money += 10000;
        }
        else if(a == 154)
        {
            money += 50000;
        }
    }

    cout << money;
}