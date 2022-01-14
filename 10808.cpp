#include <iostream>
#include <string>

using namespace std;

int main()
{
    int alpha[26] = {0};
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        alpha[str[i]-97]++;
    }

    for(int i = 0; i < 26; i++)
    {
        cout << alpha[i] << " ";
    }
}