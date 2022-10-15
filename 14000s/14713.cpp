#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    vector <queue <string>> text(n+1);
    int total_word = 0;

    for(int i = 0; i <= n; i++)
    {
        string temp_str;
        getline(cin, temp_str);
        
        stringstream ss(temp_str);
        string temp;
        char delim = ' ';
        while(getline(ss, temp, delim))
        {
            text[i].push(temp);
        }
        total_word += text[i].size();
    }

    int size = text[n].size();
    bool flag = false;
    for(int i = 0; i < size; i++)
    {   
        string str = text[n].front();
        flag = false;
        for(int j = 0; j < n; j++)
        {
            if(str == text[j].front())
            {
                text[j].pop();
                text[n].pop();
                flag = true;
                break;
            }
        }

        if(!flag)
        {
            break;
        }
    }

    total_word -= size;
    if(size != total_word)
    {
        flag = false;
    }

    if(flag)
    {
        cout << "Possible";
    }
    else
    {
        cout << "Impossible";
    }  
}