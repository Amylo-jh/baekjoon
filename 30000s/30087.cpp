#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, string> mp;
    mp.insert({"Algorithm", "204"});
    mp.insert({"DataAnalysis", "207"});
    mp.insert({"ArtificialIntelligence", "302"});
    mp.insert({"CyberSecurity", "B101"});
    mp.insert({"Network", "303"});
    mp.insert({"Startup", "501"});
    mp.insert({"TestStrategy", "105"});

    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        cout << mp[str] << "\n";
    }
}