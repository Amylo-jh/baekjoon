#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    long long b, n, m;
    cin >> b >> n >> m;
    map <string, long long> items;
    for(int i = 0; i < n; i++)
    {
        string str;
        long long price;
        cin >> str >> price;
        items[str] = price;
    }

    long long sum = 0;
    for(int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        sum += items[str];
    }

    if(sum <= b)
    {
        cout << "acceptable";
    }
    else
    {
        cout << "unacceptable";
    }
}