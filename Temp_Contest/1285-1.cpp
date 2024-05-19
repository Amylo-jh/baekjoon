#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;

    vector <int> arr(26);
    string newstr = "";
    int cnt = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(arr[str[i] - 'a'])
        {
            cnt++;
        }
        else
        {
            arr[str[i] - 'a']++;
            newstr += str[i];
        }
    }
    newstr += to_string(cnt + 4);
    newstr = to_string(1906+n) + newstr;
    str = newstr;
    newstr = "";
    for(int i = str.length()-1; i >= 0; i--)
    {
        newstr += str[i];
    }

    newstr = "smupc_" + newstr;
    cout << newstr;
}