#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--)
    {
        int max_char, line_count = 0, curr_char = 0;
        cin >> max_char;
        string str_line;
        vector <string> arr;
        cin.ignore();
        getline(cin, str_line);
        
        size_t pos = 0;
        while ((pos = str_line.find(' ')) != string::npos) {
            arr.push_back(str_line.substr(0, pos));
            str_line.erase(0, pos + 1);
        }
        if (!str_line.empty()) {
            arr.push_back(str_line);
        }

        for(string str : arr)
        {
            int len = str.length();
            if(curr_char)
            {
                if(curr_char+len+1 <= max_char)
                {
                    curr_char += len+1;
                }
                else
                {
                    line_count++;
                    curr_char = len;
                }
            }
            else
            {
                curr_char = len;
            }
        }

        cout << line_count+1 << "\n";
    }
}