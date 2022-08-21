#include <iostream>
#include <string>

using namespace std;

int main()
{
    while(1)
    {
        string str;
        int num = 0;
        cin >> str;
        if(str == "0")
        {
            break;
        }

        for(int i = 0; i < str.length(); i++)
        {
            int temp = str[i] - '0';
            num += temp;
        }

        int num2 = 0;
        while(num / 10)
        {
            num2 = 0;
            while(num)
            {
                num2 += num % 10;
                num = num / 10;
            }
            num = num2;
        }

        cout << num << endl;
    }
}