#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map <string, int> name;
    name.insert({"ChongChong", 1});

    int count = 1;
    for(int i = 0; i < n; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;

        if(name.find(str1) != name.end())
        {
            name.insert({str2, 1});
        }
        else if(name.find(str2) != name.end())
        {
            name.insert({str1, 1});
        }
    }

    cout << name.size();
}