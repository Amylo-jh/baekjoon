#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    string c, d;
    cin >> a >> b;

    c = a.substr(2,1) + a.substr(1,1) + a.substr(0,1);
    d = b.substr(2,1) + b.substr(1,1) + b.substr(0,1);

    int ci, di;
    ci = stoi(c);
    di = stoi(d);

    if(ci < di)
    {
        cout << di;
    }
    else
    {
        cout << ci;
    }
}