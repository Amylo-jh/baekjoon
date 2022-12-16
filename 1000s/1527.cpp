#include <iostream>

using namespace std;

int counter = 0;
int a, b;

void check(long long i)
{
    if(i > b)
    {
        return;
    }
    else if(a <= i && i <= b)
    {
        counter++;
    }

    check(i * 10 + 4);
    check(i * 10 + 7);
}

int main()
{
    cin >> a >> b;

    check(4);
    check(7);

    cout << counter;
}