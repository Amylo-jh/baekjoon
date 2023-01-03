#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set <string> str_set;
    string str;
    cin >> str;

    int n = str.length();

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= n - i; j++)
        {
            str_set.insert(str.substr(j, i));
        }
    }

    cout << str_set.size();
}