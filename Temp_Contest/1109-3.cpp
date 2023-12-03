#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector <pair <string, string>> mors;
    mors.push_back({"A", ".-"});
    mors.push_back({"B", "-..."});
    mors.push_back({"C", "-.-."});
    mors.push_back({"D", "-.."});
    mors.push_back({"E", "." });
    mors.push_back({"F", "..-."});
    mors.push_back({"G", "--." });
    mors.push_back({"H", "...."});
    mors.push_back({"I", ".." });
    mors.push_back({"J", ".---"});
    mors.push_back({"K", "-.-" });
    mors.push_back({"L", ".-.."});
    mors.push_back({"M", "--" });
    mors.push_back({"N", "-."});
    mors.push_back({"O", "---" });
    mors.push_back({"P", ".--."});
    mors.push_back({"Q", "--.-" });
    mors.push_back({"R", ".-."});
    mors.push_back({"S", "..." });
    mors.push_back({"T", "-"});
    mors.push_back({"U", "..-" });
    mors.push_back({"V", "...-"});
    mors.push_back({"W", ".--" });
    mors.push_back({"X", "-..-"});
    mors.push_back({"Y", "-.--" });
    mors.push_back({"Z", "--.."});
    mors.push_back({"1", ".----" });
    mors.push_back({"2", "..---"});
    mors.push_back({"3", "...--" });
    mors.push_back({"4", "....-"});
    mors.push_back({"5", "....." });
    mors.push_back({"6", "-...."});
    mors.push_back({"7", "--..." });
    mors.push_back({"8", "---.."});
    mors.push_back({"9", "----." });
    mors.push_back({"0", "-----"});
    mors.push_back({",", "--..--" });
    mors.push_back({".", ".-.-.-"});
    mors.push_back({"?", "..--.." });
    mors.push_back({":", "---..."});
    mors.push_back({"-", "-....-" });
    mors.push_back({"@", ".--.-."});

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int i = 0; i < mors.size(); i++)
        {
            if(str == mors[i].second)
            {
                cout << mors[i].first;
                break;
            }
        }
    }
}