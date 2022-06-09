#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set <string> chat;
    int n;
    int hello_count = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        if(str == "ENTER")
        {
            chat.clear();
        }
        else
        {
            if(auto [iter, success] = chat.insert(str); success)
            {
                hello_count++;
            }
        }
    }

    cout << hello_count;
}