#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <long long> digit;

long long getone(long long num)
{
    long long answer = num & 1;

    for(int i = 55; i > 0; i--)
    {
        if(num & (1LL << i))
        {
            answer += digit[i-1] + (num - (1LL << i) + 1);
            num -= (1LL << i);
        }
    }

    return answer;
}

int main()
{
    long long a, b;
    cin >> a >> b;

    digit.push_back(1);
    for(int i = 1; i < 55; i++)
    {
        digit.push_back(digit[i-1]*2 + pow(2, i));
    }

    cout << getone(b) - getone(a-1);
}