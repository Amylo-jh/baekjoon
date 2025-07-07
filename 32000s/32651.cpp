#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if(n <= 100000 && n % 2024 == 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}