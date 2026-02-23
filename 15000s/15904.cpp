#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<char> arr;
    vector<char> answer = {'U', 'C', 'P', 'C'};
    int idx = 0;
    bool flag = false;
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
        {
            arr.push_back(str[i]);
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == answer[idx])
        {
            idx++;
            if (idx == 4)
            {
                flag = true;
            }
        }
    }
    if (flag)
    {
        cout << "I love UCPC";
    }
    else
    {
        cout << "I hate UCPC";
    }
}