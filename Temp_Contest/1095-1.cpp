#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    double score = 0;
    int subject = 0;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'A')
        {
            score += 4;
            subject++;
        }
        else if(str[i] == 'B')
        {
            score += 3;
            subject++;
        }
        else if(str[i] == 'C')
        {
            score += 2;
            subject++;
        }
        else if(str[i] == 'D')
        {
            score += 1;
            subject++;
        }
        else if(str[i] == 'F')
        {
            subject++;
        }
        else if(str[i] == '+')
        {
            score += 0.5;
        }
    }

    cout << score / subject;
}