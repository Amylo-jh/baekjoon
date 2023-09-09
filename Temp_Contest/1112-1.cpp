#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int counter = 0;
    for(int i = 0; i < str.length()-3; i++)
    {
        if(str[i] == 'D' && str[i+1] == 'K' && str[i+2] == 'S' && str[i+3] == 'H')
        {   
            counter++;
        }
    }

    cout << counter;
}