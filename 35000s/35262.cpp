#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, k, count = 0, max_count = 0;
    string str;
    cin >> n >> k >> str;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == '1')
        {
            count = 0;
        }
        else
        {
            count++;
            max_count = max(max_count, count);
        }
    }
    if(max_count >= k)
    {
        cout << "0";
    }
    else
    {
        cout << "1";
    }
}