#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    pair <long long, long long> p1;
    pair <long long, long long> p2;

    for(long long i = 0; i < 4; i++)
    {
        long long x, y;
        cin >> x >> y;
        p1.first += x;
        p1.second += y;
    }
    for(long long i = 0; i < 4; i++)
    {
        long long x, y;
        cin >> x >> y;
        p2.first += x;
        p2.second += y;
    }
    
    long long y_diff = p1.second - p2.second;
    long long x_diff = p1.first - p2.first;
    long long gcd_diff = gcd(y_diff, x_diff);
    y_diff /= gcd_diff;
    x_diff /= gcd_diff;

    if(x_diff < 0)
    {
        y_diff *= -1;
        x_diff *= -1;
    }

    if(x_diff == 1)
    {
        cout << y_diff << " ";
    }
    else
    {
        cout << y_diff << "/" << x_diff << " ";
    }

    pair <long long, long long> q1 = {p1.second, 4};
    pair <long long, long long> q2 = {y_diff * p1.first, x_diff*4};
    long long q_lcm = lcm(q1.second, q2.second);

    if(q1.second != q_lcm)
    {
        long long mul = q_lcm / q1.second;
        q1.first *= mul;
        q1.second *= mul;
    }
    if(q2.second != q_lcm)
    {
        long long mul = q_lcm / q2.second;
        q2.first *= mul;
        q1.first *= mul;
    }

    q1.first -= q2.first;
    long long q_gcd = gcd(q1.first, q1.second);
    q1.first /= q_gcd;
    q1.second /= q_gcd;
    
    if(q1.second != 1)
    {
        cout << q1.first << "/" << q1.second;
    }
    else
    {
        cout << q1.first;
    }
}