#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    string bomb;
    string new_str;
    string bomb_end;

    cin >> str;
    cin >> bomb;
    
    int bomb_length = bomb.length();
    int new_str_length = 0;

    bomb_end = bomb.substr(bomb.length() -1, 1);

    for(int i = 0; i < str.length(); i++)
    {
        string tempstr = str.substr(i, 1);
        new_str.append(tempstr);
        new_str_length++;

        if(tempstr == bomb_end && new_str_length >= bomb_length)
        {
            if(new_str.substr(new_str_length - bomb_length, bomb_length) == bomb)
            {
                for(int j = 0; j < bomb_length; j++)
                {
                    new_str.pop_back();
                }
                new_str_length = new_str_length - bomb_length;
            }
        }
    }

    if(new_str.length() == 0)
    {
        cout << "FRULA";
    }
    else
    {
        cout << new_str;
    }
}