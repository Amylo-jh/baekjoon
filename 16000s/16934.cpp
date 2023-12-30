#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class username
{
private:
    map <char, username*> child;
    int count = 0;
public:
    void insert(string str, int index, bool printed)
    {
        if(index == str.length())
        {
            if(count != 0)
            {
                cout << str;
                cout << count+1;
                cout << "\n";
            }
            else if(!printed)
            {
                cout << str;
                cout << "\n";
            }
            count++;
            return;
        }
        else 
        {
            if(child.find(str[index]) == child.end() && !printed)
            {
                for(int i = 0; i <= index; i++)
                {
                    cout << str[i];
                }
                cout << "\n";
                printed = true;
            }

            if(child.find(str[index]) == child.end())
            {
                child[str[index]] = new username();
            }

        }

        child[str[index]]->insert(str, index+1, printed);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    username* namelist = new username;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        namelist->insert(str, 0, false);
    }
}