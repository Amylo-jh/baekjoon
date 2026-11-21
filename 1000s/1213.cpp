#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> arr(26);
    string str, a, b, c;
    bool flag = true;
    
    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        arr[str[i] - 'A']++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] % 2 == 0)
        {
            a.append(arr[i]/2, 'A' + i);
        }
        else if(arr[i] % 2)
        {
            if(flag)
            {
                flag = false;
                a.append(arr[i]/2, 'A' + i);
                c = 'A' + i;
            }
            else
            {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }
    }
    cout << a << c;
    reverse(a.begin(), a.end());
    cout << a;
}