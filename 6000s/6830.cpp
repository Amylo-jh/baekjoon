#include <iostream>
#include <string>

using namespace std;

int main()
{
    string coldest;
    int min_temp = INT32_MAX;

    string city;
    int temp;
    while(1)
    {
        if(cin.eof())
        {
            cout << coldest;
            break;
        }

        cin >> city >> temp;
        if(temp < min_temp)
        {
            coldest = city;
            min_temp = temp;
        }
    }
}