#include <iostream>

using namespace std;

int main()
{
    int x1, x2;
    int a, b, c, d, e;
    cin >> x1 >> x2 >> a >> b >> c >> d >> e;

    b = b-d;
    c = c-e;

    a = a/3;
    b = b/2;

    int start = a*x1*x1*x1 + b*x1*x1 + c*x1;
    int end = a*x2*x2*x2 + b*x2*x2 + c*x2;

    cout << end - start;
}