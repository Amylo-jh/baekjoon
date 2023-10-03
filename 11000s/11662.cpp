#include <iostream>
#include <cmath>

using namespace std;

pair <int, int> a;
pair <int, int> b;
pair <int, int> c;
pair <int, int> d;

pair <double, double> minho(double p)
{
    return {a.first + (b.first - a.first)*(p/100), a.second + (b.second - a.second)*(p/100) };
}

pair <double, double> kangho(double p)
{
    return {c.first + (d.first - c.first)*(p/100), c.second + (d.second - c.second)*(p/100) };
}

int main()
{
    
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;

    double lo = 0;
    double hi = 100;
    double answer = 20000;

    while(hi - lo >= 1e-8)
    {
        double p = (lo*2 + hi) / 3; // 1:2
        double q = (lo + 2*hi) / 3; // 2:1

        pair <double, double> m_p = minho(p);
        pair <double, double> m_q = minho(q);
        pair <double, double> k_p = kangho(p);
        pair <double, double> k_q = kangho(q);

        double pDist = sqrt(pow(m_p.first - k_p.first, 2) + pow(m_p.second - k_p.second, 2));
        double qDist = sqrt(pow(m_q.first - k_q.first, 2) + pow(m_q.second - k_q.second, 2));

        answer = min(answer, min(pDist, qDist));

        if(pDist > qDist)
        {
            lo = p;
        }
        else
        {
            hi = q;
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << answer;
}