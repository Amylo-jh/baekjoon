#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map <string, int> extension;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        int position = str.find(".");
        str = str.substr(position + 1, str.length() - position - 1);

        if(auto [iter, success] = extension.insert({str, 1}); success == false)
        {
            iter->second++;
        }
    }

    for(auto iter : extension)
    {
        cout << iter.first << " " << iter.second << "\n";
    }
}