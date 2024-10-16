#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int a, b;
    string sa, sb;
    cin >> a >> b >> sa >> sb;

    vector <int> alpha = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
    vector <int> str;

    for(int i = 0; i < max(a, b); i++)
    {
        if(i < a)
        {
            str.push_back(alpha[sa[i] - 'A']);
        }
        if(i < b)
        {
            str.push_back(alpha[sb[i] - 'A']);
        }
    }

    while(str.size() > 2)
    {
        for(int i = 0; i < str.size()-1; i++)
        {
            str[i] = (str[i] + str[i+1]) % 10;
        }
        str.pop_back();
    }

    if(str[0] != 0)
    {
        cout << str[0];
    }
    cout << str[1] << "%";
}