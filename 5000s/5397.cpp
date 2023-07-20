#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;
    while(tc--)
    {
        list <char> password;
        list <char>::iterator itr = password.begin();
        string str;
        cin >> str;
        
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == '<')
            {
                if(itr != password.begin())
                {
                    itr--;
                }
            }
            else if(str[i] == '>')
            {
                if(itr != password.end())
                {
                    itr++;
                }
            }
            else if(str[i] == '-')
            {
                if(itr!= password.begin())
                {
                    itr = password.erase(--itr);
                }
            }
            else
            {
                password.insert(itr, str[i]);
            }
        }

        itr = password.begin();
        for(int i = 0; i < password.size(); i++)
        {
            cout << *itr;
            itr++;
        }
        cout << "\n";
    }
}