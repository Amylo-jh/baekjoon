#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;

    for(int i = 2; i < str.length(); i++)
    {
        if(str[i-2] == 'P' && str[i-1] == 'S')
        {
            while(str[i] == '4' || str[i] == '5')
            {
                str.erase(i, 1);
            }
        }
    }

    cout << str << endl;
}