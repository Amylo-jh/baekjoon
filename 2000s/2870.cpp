#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b)
{
    if(a.length() == b.length())
    {
        return a < b;
    }
    return a.length() < b.length();
}

int main()
{
    int n;
    cin >> n;

    vector <string> arr;
    string temp_str;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < str.length(); j++)
        {
            if('0' <= str[j] && str[j] <= '9')
            {
                temp_str += str[j];
            }
            else
            {
                if(temp_str.length() != 0)
                {
                    while(temp_str.length() > 1 && temp_str[0] == '0')
                    {
                        temp_str.erase(0, 1);
                    }
                    arr.push_back(temp_str);
                    temp_str = "";
                }
            }
        }
        if(temp_str.length() != 0)
        {
            while(temp_str.length() > 1 && temp_str[0] == '0')
            {
                temp_str.erase(0, 1);
            }
            arr.push_back(temp_str);
            temp_str = "";
        }
    }


    sort(arr.begin(), arr.end(), comp);
    for(string str : arr)
    {
        cout << str << "\n";
    }


}