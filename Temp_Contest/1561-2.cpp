#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int sum = 1;
    int score = 1;
    for(int i = 1; i < str.length(); i++)
    {
        if(str[i] > str[i-1])
        {
            score++;
        }
        else
        {
            score = 1;
        }
        sum += score;
    }
    cout << sum;
}
