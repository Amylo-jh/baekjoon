#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;

    if(a > b)
    {
        long long temp = a;
        a = b;
        b = temp;
    }
    
    int count = b - a - 1;
    if(count < 0)
    {
        count = 0;
    }

    cout << count << "\n";
    for(long long i = a+1; i < b; i++)
    {
        cout << i << " ";
    }
}