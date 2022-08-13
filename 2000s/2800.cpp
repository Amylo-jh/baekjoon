#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack <int> brackets;
    vector <int> marking;
    set <string> result;
    string str;
    cin >> str;

    int count = 1;
    for(int i = 0; i < str.length(); i++)
    {
        string temp_str= str.substr(i, 1);
        if(temp_str == "(")
        {
            brackets.push(count);
            marking.push_back(count);
            count++;
        }
        else if(temp_str == ")")
        {
            marking.push_back(brackets.top());
            brackets.pop();
        }
        else
        {
            marking.push_back(0);
        }
    }

    for(int i = 1; i < pow(2, count-1); i++)
    {
        vector <bool> is_turn_off = {false};
        string str_curr_result = "";
        int k = i;
        
        for(int j = 0; j < count; j++)
        {
            is_turn_off.push_back(k % 2);
            k = k / 2;
        }

        for(int j = 0; j < str.length(); j++)
        {
            if(is_turn_off[marking[j]] == false)
            {
                str_curr_result += str[j];
            }
        }
        result.insert(str_curr_result);
    }

    //remove duplicates are important
    for(string result_str : result)
    {
        cout << result_str << "\n";
    }
}