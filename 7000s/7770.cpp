#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    n--;
    int count = 1;
    int next_use = 5;
    while(n >= next_use)
    {
        count++;
        n -= next_use;
        next_use += count*4;
    }
    cout << count;
}