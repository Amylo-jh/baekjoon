#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>

using namespace std;

int main()
{
    string str;
    cin >> str;

    string intpart = str.substr(0, str.find('.'));
    string decpart = str.substr(str.find('.')+1);
    long long up = stoll(intpart+decpart);
    long long dn = pow(10, decpart.size());
    long long g = gcd(up, dn);
    up /= g;
    dn /= g;

    vector <int> answer(6);
    long long sum = up;
    long long mul = dn;
    long long divider = sum / mul;
    long long diff = sum - mul * divider;
    answer[divider+1] += diff;
    answer[divider] += mul - diff;

    for(int i = 1; i <= 5; i++)
    {
        cout << answer[i] << ' ';
    }
}