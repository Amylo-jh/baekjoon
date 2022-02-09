#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    regex word("([a-zA-Z]|-)+");


    string input_str;
    string max_str = "";

    while(true)
    {
        cin >> input_str;
        smatch match_str;

        if(input_str == "E-N-D")
        {
            break;
        }

        while(regex_search(input_str, match_str, word))
        {
            string test = match_str[0];

            if(max_str.length() < match_str[0].length())
            {
                max_str = match_str[0];

/*                 cout << "====" << endl;
                for(auto& match_strs : match_str)
                {
                    cout << match_str.str() << endl;
                } */
            }

            input_str = match_str.suffix();
        }
    }

    for(int i = 0; i < max_str.length(); i++)
    {
        max_str[i] = tolower(max_str[i]);
    }

    cout << max_str;
}