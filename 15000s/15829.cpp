#include <iostream>
#include <string>

using namespace std;

int main()
{
    int l;
    long long hash = 0;
    string str;

    cin >> l;
    cin >> str;

    long long r = 1;
    for(int i = 0; i < l; i++)
    {
        char ch = str[i] - 96;
        long long each_hash = ch * r;
        hash += each_hash;
        r = (r * 31) % 1234567891;
        hash %= 1234567891;
    }

    cout << hash;
}