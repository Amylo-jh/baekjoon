#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string temp;
    int total = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        total = total + temp.length();
    }

    cout << total;
}