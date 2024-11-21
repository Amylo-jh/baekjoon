#include <iostream>
#include <string>

using namespace std;

int main()
{
    int count = 0;
    int num = 0;
    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '1')
        {
            count++;
        }
        else
        {
            num *= 10;
            num += (str[i] - '0'); 
        }
    }

    while(num)
    {
        if(num % 10 == 1)
        {
            num /= 10;
        }
        else
        {
            num--;
        }
        count++;
    }

    cout << count;
}