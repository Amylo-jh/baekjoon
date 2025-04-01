#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    while(1)
    {
        string str;
        cin >> str;

        if(str == "#")
        {
            break;
        }

        bool flag  = true;
        for(int i = 0; i < str.size()-1; i++)
        {
            int diff = str[i+1] - str[i];
            if(diff < 0)
            {
                diff += 7;
            }
            if(!((diff == 2) || (diff == 4) || (diff == 6)))
            {
                flag = false;
                break;
            }
        }
        int diff = str[str.size()-1] - str[0];
        if(diff < 0)
        {
            diff += 7;
        }
        if(!(diff != 2 || diff != 4 || diff != 6))
        {
            flag = false;
        }

        if(flag)
        {
            cout << "That music is beautiful.\n";
        }
        else
        {
            cout << "Ouch! That hurts my ears.\n";
        }
    }
}