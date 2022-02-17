#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void tokenize(string const &str, const char delim, vector <string> &out)
{
    stringstream ss(str);

    string s;
    while(getline(ss, s, delim))
    {
        out.push_back(s);
    }
}

int main()
{
    int tc;
    cin >> tc;
    cin.ignore();

    for(int t = 0; t < tc; t++)
    {
        string sound;
        vector <string> allsound;
        vector <string> animals;

        getline(cin, sound);
        const char delim = ' ';

        tokenize(sound, delim, allsound);

        while(1)
        {
            string temp;
            string t1;
            string t2;

            cin >> t1 >> t2 >> temp;

            if(t1 == "what")
            {
                cin >> t1 >> t2;
                cin.ignore();
                break;
            }

            animals.push_back(temp);
        }

        for(int i = 0; i < animals.size(); i++)
        {
            for(int j = 0; j < allsound.size(); j++)
            {
                if(allsound[j] == animals[i])
                {
                    allsound[j].erase();
                }
            }
        }

        for(int i = 0; i < allsound.size(); i++)
        {
            if(allsound[i].empty())
            {
                continue;
            }
            else
            {
                cout << allsound[i] << " ";
            }
        }
        cout << endl;
    }
}