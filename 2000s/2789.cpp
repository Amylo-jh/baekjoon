#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    string cambridge = "CAMBRIDGE";
    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        bool flag = true;
        for(int j = 0; j < cambridge.length(); j++)
        {
            if(str[i] == cambridge[j])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout << str[i];
        }
    }
}