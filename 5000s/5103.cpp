#include <iostream>
#include <string>

using namespace std;

int main()
{
    while(1)
    {
        string dvd;
        cin >> dvd;
        if(dvd == "#")
        {
            break;
        }
    
        int maxdvd, inv, tc;
        cin >> maxdvd >> inv >> tc;
        while(tc--)
        {
            string s;
            int count;
            cin >> s >> count;
            if(s == "S")
            {
                inv = max(0, inv-count);
            }
            else if(s == "R")
            {
                inv = min(maxdvd, inv+count);
            }
        }
        cout << dvd << " " << inv << "\n";
    }
}