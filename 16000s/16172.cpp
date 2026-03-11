#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b, c;
    int pa = 0, pb = 0;
    bool flag = false;
    cin >> a >> c;
    for (int i = 0; i < a.length(); i++)
    {
        if ('0' <= a[i] && a[i] <= '9')
        {
            continue;
        }
        b.push_back(a[i]);
    }
    if (b.find(c) != string::npos)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}