#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string str;
        cin >> str;
        int count = 0;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == 'D')
            {
                break;
            }
            count++;
        }
        cout << count << "\n";
    }
}