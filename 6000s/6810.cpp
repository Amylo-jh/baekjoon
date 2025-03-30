#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int sum = 91;
    sum += a + b*3 + c;

    cout << "The 1-3-sum is " << sum;
}