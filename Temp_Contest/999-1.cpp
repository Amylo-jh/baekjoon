#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    if(a > b)
    {
        cout << "Subway";
    }
    else if(b > a)
    {
        cout << "Bus";
    }
    else
    {
        cout << "Anything";
    }
}