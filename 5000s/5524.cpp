#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        
        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] < 92)
            {
                str[j] += 32;
            }
        }

        cout << str << "\n";
    }
}