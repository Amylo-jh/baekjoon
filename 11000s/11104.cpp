#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        string str;
        int answer = 0;
        cin >> str;
        for(int i = 0; i < str.length(); i++)
        {
            answer *= 2;
            answer += str[i] - '0';
        }
        cout << answer << "\n";
    }
}