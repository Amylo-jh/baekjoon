#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    long long total = 0;
    string num;
    int length;
    long long each_digit;

    string add_num;

    cin >> num;

    length = num.length();

    char temp;

    for(int i = 0; i < length; i++)
    {
        temp = num[i];
        each_digit = atoi(&temp);
        add_num = "";

        for(int j = 0; j < length; j++)
        {
            // total = total + each_digit * (long long)pow(10, j);

            add_num = add_num + to_string(each_digit);
        }
        total = total + stoll(add_num);
    }
    cout << total;
}