#include <iostream>
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

        bool output = false;
        for(int i = 0; i < str.length(); i++)
        {
            string newstr = "";
            for(int j = 0; j < str.length(); j++)
            {
                if(i != j)
                {
                    newstr += str[j];
                }
            }
            bool same = true;
            int len = newstr.length();
            for(int j = 0; j < len; j++)
            {
                if(newstr[j] != newstr[len-j-1])
                {
                    same = false;
                    break;
                }
            }

            if(same)
            {
                output = true;
                cout << newstr << "\n";
                break;
            }
        }

        if(!output)
        {
            cout << "not possible\n";
        }
    }
}