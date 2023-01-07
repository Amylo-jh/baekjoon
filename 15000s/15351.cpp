#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    cin.ignore();
    while(tc--)
    {
        string str;
        getline(cin, str);

        int score = 0;

        for(int i = 0; i < str.length(); i++)
        {
            if(65 <= str[i] && str[i] <= 90)
            {
                score += str[i] - 64;
            }
        }

        if(score == 100)
        {
            cout << "PERFECT LIFE\n";
        }
        else
        {
            cout << score << "\n";
        }
    }
}