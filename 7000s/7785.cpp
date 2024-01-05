#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    set <string> person;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str, cmd;
        cin >> str >> cmd;

        if(cmd == "enter")
        {
            person.insert(str);
        }
        else
        {
            person.erase(str);
        }
    }

    auto i = person.end();
    while(i != person.begin())
    {
        i--;
        cout << *i << "\n";
    }
}