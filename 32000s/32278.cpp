#include <iostream>

using namespace std;

int main()
{
    short a;
    int b;
    long long c;
    long long n;
    cin >> n;

    a = n;
    b = n;
    c = n;

    if(a == n)
    {
        cout << "short";
    }
    else if(b == n)
    {
        cout << "int";
    }
    else
    {
        cout << "long long";
    }
}