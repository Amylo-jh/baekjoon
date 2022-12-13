#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    string new_str;
    cin >> str;

    int len = str.length();
    int odd = 0;
    int even = 0;
    vector <bool> vec(len);
    
    
    for(int i = 0; i < len; i++)
    {
        if(str[i] == '0')
        {
            even++;
        }        
        else
        {
            odd++;
        }
    }
    
    int counter = 0;
    for(int i = 0; i < len; i++)
    {
        if(str[i] == '1')
        {
            if(counter < odd / 2)
            {
                vec[i] = false;
                counter++;
            }
            else
            {
                vec[i] = true;
            }
        }
    }
    
    counter = 0;
    for(int i = len-1; i >= 0; i--)
    {
        if(str[i] == '0')
        {
            if(counter < even / 2)
            {
                vec[i] = false;
                counter++;
            }
            else
            {
                vec[i] = true;
            }
        }
    }

    for(int i = 0; i < len; i++)
    {
        if(vec[i])
        {
            new_str += str[i];
        }
    }

    cout << new_str;
}