#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, year = 0;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        string study;
        cin >> study >> num;
        if (num > year)
        {
            str = study;
            year = num;
        }
    }
    cout << str;
}