#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string x, string y)
{
    if(x.length() == y.length())
    {
        return x < y;
    }
    return x.length() < y.length();
}

int main()
{
    int word_count;
    vector <string> words = {};
    string temp;

    cin >> word_count;

    for(int i = 0; i < word_count; i++)
    {
        cin >> temp;
        words.push_back(temp);
    }

    sort(words.begin(), words.end(), compare);

    temp = "";

    for(int i = 0; i < word_count; i++)
    {
        if(temp == words[i])
        {
            continue;
        }
        cout << words[i] << endl;
        temp = words[i];
    }
}