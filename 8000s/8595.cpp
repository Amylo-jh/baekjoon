#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    string str;
    cin >> num >> str;

    long long sum = 0;
    long long tmp = 0;
    for(int i = 0; i < num; i++)
    {
        if('0' <= str[i] && str[i] <= '9')
        {
            tmp = tmp * 10 + str[i] - '0';
        }
        else
        {
            sum += tmp;
            tmp = 0;
        }
    }

    sum += tmp;
    cout << sum;
}