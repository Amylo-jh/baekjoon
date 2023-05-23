#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double d, h1, w1;
    cin >> d >> h1 >> w1;

    d = d*d;
    double h, w;
    h = (d / (h1*h1+w1*w1)) * h1* h1;
    w = (d / (h1*h1+w1*w1)) * w1* w1;

    h = sqrt(h);
    w = sqrt(w);

    h = floor(h);
    w = floor(w);
    cout << h << " " << w;
}