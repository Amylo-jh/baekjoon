#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str, a;
    cin >> str >> a;
    int count = 0;
    int idx = 0;

    while(idx < a.length())
    {
        count++;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == a[idx])
            {
                idx++;
            }
            if(idx == a.length())
            {
                break;
            }
        }
    }
    
    cout << count;
}