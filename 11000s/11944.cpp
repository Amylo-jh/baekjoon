#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int n, m;
    cin >> n >> m;

    string tmp = to_string(n);
    for(int i = 0; i < n; i++)
    {
        str += tmp;
    }
    str = str.substr(0, m);
    cout << str;
}