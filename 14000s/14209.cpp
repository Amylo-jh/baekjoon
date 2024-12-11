#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    int score = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < str.size(); j++)
        {
            if(str[j] == 'A')
            {
                score += 4;
            }
            else if(str[j] == 'K')
            {
                score += 3;
            }
            else if(str[j] == 'Q')
            {
                score += 2;
            }
            else if(str[j] == 'J')
            {
                score += 1;
            }
        }
    }
    cout << score;
}