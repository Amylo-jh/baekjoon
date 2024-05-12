#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m;
    string str;
    cin >> n >> m >> str;

    if(str == "freeze")
    {
        cout << min(n, m);
    }
    else if(str == "heat")
    {
        cout << max(n, m);
    }
    else if(str == "auto")
    {
        cout << m;
    }
    else
    {
        cout << n;
    }
}