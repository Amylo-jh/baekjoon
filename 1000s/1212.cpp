#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str, result = "";
    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '0')
        {
            result += "000";    
        }
        else if(str[i] == '1')
        {
            result += "001";
        }
        else if(str[i] == '2')
        {
            result += "010";
        }
        else if(str[i] == '3')
        {
            result += "011";
        }
        else if(str[i] == '4')
        {
            result += "100";
        }
        else if(str[i] == '5')
        {
            result += "101";
        }
        else if(str[i] == '6')
        {
            result += "110";
        }
        else if(str[i] == '7')
        {
            result += "111";
        }
    }

    if(result == "000")
    {
        cout << "0\n";
        return 0;
    }
    int idx = 0;
    while(result[idx] == '0')
    {
        idx++;
    }
    cout << result.substr(idx) << "\n";
}