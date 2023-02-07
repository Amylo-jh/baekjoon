#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int score = str.length() + 2;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '_')
        {
            score += 5;
        }
    }

    cout << score;
}