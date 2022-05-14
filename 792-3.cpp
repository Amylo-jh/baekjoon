#include <iostream>
#include <string>

using namespace std;

int main()
{
    int day;
    cin >> day;

    string str;
    cin >> str;

    int chicken = 0;
    int other = 0;

    for(int i = 0; i < day; i++)
    {
        char temp= str[i];

        if(temp == 'C')
        {
            chicken++;
        }
        else
        {
            other++;
        }
    }

    int max_chicken_day = chicken / (other + 1);

    if(chicken % (other + 1))
    {
        max_chicken_day++;
    }

    cout << max_chicken_day;
}
