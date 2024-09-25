#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;

    long long count = 0;
    long long i = 1;
    while(i*i < a)
    {
        i++;
    }

    for(; i*i <= b; i++)
    {
        string s = to_string(i*i);
        reverse(s.begin(), s.end());

        long long new_num = stoll(s);
        long long new_i = sqrt(new_num);

        if(s[0] == '0')
        {
            continue;
        }

        if(new_i*new_i == new_num)
        {
            count++;
        }
    }

    cout << count;
}