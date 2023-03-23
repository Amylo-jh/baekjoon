#include <iostream>
#include <string>

using namespace std;

int main()
{
    int counter = 0;
    for(int i = 0; i < 8; i++)
    {
        string str;
        cin >> str;

        for(int j = 0; j < 8; j++)
        {
            if((i + j) % 2 == 0 && str[j] == 'F')
            {
                counter++;
            }
        }
    }
    cout << counter;
}