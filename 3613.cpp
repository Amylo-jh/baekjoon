#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool eval_c(string &str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(!( (97 <= str[i] && str[i] <= 122) || str[i] == 95))
        {
            return false;
        }
    }

    string remake_str;

    bool nextBig = false;
    for(int i = 0; i < str.length(); i++)
    {
        string temp = str.substr(i, 1);

        if(i == str.length() - 1 || i == 0)
        {
            if(temp == "_")
            {
                return false;
            }
        }

        if(temp == "_")
        {
            nextBig = true;
            if(str.substr(i+1, 1) == "_")
            {
                return false;
            }
            continue;
        }

        if(nextBig)
        {
            transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
            nextBig = false;
        }

        remake_str = remake_str + temp;
    }
    str = remake_str;

    return true;
}

bool eval_java(string &str)
{
    if(!(97 <= str[0] && str[0] && 122))
    {
        return false;
    }


    for(int i = 0; i < str.length(); i++)
    {
        char temmpp = str[i];
        if(!( (65 <= str[i] && str[i] <= 90) || (97 <= str[i] && str[i] <= 122) ))
        {
            return false;
        }
    }

    string remake_str;
    string underbar = "_";

    for(int i = 0; i < str.length(); i++)
    {
        string temp = str.substr(i, 1);

        if(65 <= temp[0] && temp[0] <= 90)
        {
            remake_str = remake_str + underbar;
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        }

        remake_str = remake_str + temp;
    }
    str = remake_str;

    return true;
}


int main()
{
    string inputstr;
    cin >> inputstr;

    bool is_c = false;
    bool is_java = false;

    is_c = eval_c(inputstr);
    if(!is_c)
    {
        is_java = eval_java(inputstr);
    }
    
    if(!(is_c || is_java))
    {
        cout << "Error!";
        return 0;
    }

    cout << inputstr;
}