#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;

    for(int i = 0; i < n-3; i++)
    {
        if(str[i] == 'g' && str[i+1] == 'o' && str[i+2] == 'r' && str[i+3] == 'i')
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}