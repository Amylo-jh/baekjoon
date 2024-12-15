#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    int count = 2;
    while(1)
    {
        getline(cin, str);
        if(str == "Was it a cat I saw?")
        {
            break;
        }

        for(int i = 0; i < str.size(); i += count)
        {
            cout << str[i];
        }
        cout << '\n';
        count++;
    }
}