#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string str;
    cin >> str;

    string intpart = str.substr(0, str.find('.'));
    string decpart = str.substr(str.find('.')+1);
    long long intpartnum = stoll(intpart);
    long long decpartnum = stoll(decpart);
    int len = decpart.size();
    if(decpart == "0")
    {
        len = 0;
    }

    while(decpartnum != 0 && decpartnum % 10 == 0)
    {
        decpartnum /= 10;
        len--;
    }

    vector <int> arr(10);
    
    long long temp = decpartnum;
    while(decpartnum % 2 == 0 || decpartnum % 5 == 0)
    {
        if(decpartnum == 0)
        {
            break;
        }
        if(decpartnum % 2 == 0)
        {
            arr[2]++;
            decpartnum /= 2;
        }
        else if(decpartnum % 5 == 0)
        {
            arr[5]++;
            decpartnum /= 5;
        }
    }
    decpartnum = temp;

    int mul = 1;
    int mul_2 = max(0, len - arr[2]);
    int mul_5 = max(0, len - arr[5]);
    mul *= pow(2, mul_2);
    mul *= pow(5, mul_5);

    long long sum = intpartnum * mul + (decpartnum * mul / pow(10, len));

    vector <int> answer(6);

    long long divider = sum / mul;
    long long diff = sum - mul * divider;
    answer[divider+1] += diff;
    answer[divider] += mul - diff;

    for(int i = 1; i <= 5; i++)
    {
        cout << answer[i] << ' ';
    }
}