#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string str1;
    string str2;
    string new_str1 = "";
    string new_str2 = "";
    int str1_aeiou[5] = {0};
    int str2_aeiou[5] = {0};

    cin >> n >> str1 >> str2;

    for(int i = 0; i < n; i++)
    {
        string temp = str1.substr(i, 1);

        if(temp == "a")
        {
            str1_aeiou[0]++;
            continue;
        }
        else if(temp == "e")
        {
            str1_aeiou[1]++;
            continue;
        }
        else if(temp == "i")
        {
            str1_aeiou[2]++;
            continue;
        }
        else if(temp == "o")
        {
            str1_aeiou[3]++;
            continue;
        }
        else if(temp == "u")
        {
            str1_aeiou[4]++;
            continue;
        }
        else
        {
            new_str1.append(temp);
        }
    }

    for(int i = 0; i < n; i++)
    {
        string temp = str2.substr(i, 1);

        if(temp == "a")
        {
            str2_aeiou[0]++;
            continue;
        }
        else if(temp == "e")
        {
            str2_aeiou[1]++;
            continue;
        }
        else if(temp == "i")
        {
            str2_aeiou[2]++;
            continue;
        }
        else if(temp == "o")
        {
            str2_aeiou[3]++;
            continue;
        }
        else if(temp == "u")
        {
            str2_aeiou[4]++;
            continue;
        }
        else
        {
            new_str2.append(temp);
        }
    }

    bool is_duramuri = true;

    //조건1
    for(int i = 0; i < 5; i++)
    {
        if(str1_aeiou[i] != str2_aeiou[i])
        {
            is_duramuri = false;
        }
    }
    //조건2
    if(str1[0] != str2[0] || str1[n-1] != str2[n-1])
    {
        is_duramuri = false;
    }

    //조건 1, 조건3
        if(new_str1 != new_str2)
    {
        is_duramuri = false;
    }

    if(is_duramuri)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}