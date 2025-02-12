#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    vector <pair <string, int>> money;
    money = {
        {"Franklin", 100},
        {"Grant", 50},
        {"Jackson", 20},
        {"Hamilton", 10},
        {"Lincoln", 5},
        {"Washington", 1}
    };
    for(int i = 0; i < n; i++)
    {
        string str, word = "";
        vector <string> words;
        int answer = 0;
        getline(cin, str);
        for(int j = 0; j < str.size(); j++)
        {
            if(str[j] == ' ')
            {
                words.push_back(word);
                word = "";
            }
            else
            {
                word += str[j];
            }
        }
        words.push_back(word);

        for(int j = 0; j < words.size(); j++)
        {
            for(int k = 0; k < money.size(); k++)
            {
                if(words[j] == money[k].first)
                {
                    answer += money[k].second;
                    break;
                }
            }
        }

        cout << "$" << answer << "\n";
    }
}