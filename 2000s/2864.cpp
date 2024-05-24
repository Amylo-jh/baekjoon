#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2;
    
    for(int i = 0; i < s1.length(); i++)
    {
        if(s1[i] == '5')
        {
            s3 += '6';
        }
        else
        {
            s3 += s1[i];
        }
    }
    for(int i = 0; i < s2.length(); i++)
    {
        if(s2[i] == '5')
        {
            s4 += '6';
        }
        else
        {
            s4 += s2[i];
        }
    }

    int max_value = stoi(s3) + stoi(s4);

    s3 = "";
    s4 = "";
    for(int i = 0; i < s1.length(); i++)
    {
        if(s1[i] == '6')
        {
            s3 += '5';
        }
        else
        {
            s3 += s1[i];
        }
    }
    for(int i = 0; i < s2.length(); i++)
    {
        if(s2[i] == '6')
        {
            s4 += '5';
        }
        else
        {
            s4 += s2[i];
        }
    }

    int min_value = stoi(s3) + stoi(s4);

    cout << min_value << " " << max_value;
}