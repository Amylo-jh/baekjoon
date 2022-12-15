#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string str;
    
    cin >> n >> str;
    
    bool pulled = false;
    int time = 1;
    int killed = 0;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'P')
        {
            if(time == 1)
            {
                pulled = !pulled;
            }
            
            if(time == 2)
            {
                killed = 6;
            }
        }
        else if(str[i] == 'W')
        {
            time++;
        }
    }

    if(time < 3)
    {
        cout << 0;
    }
    else if(killed == 6)
    {
        cout << 6;
    }
    else
    {
        if(pulled)
        {
            cout << 1;
        }
        else
        {
            cout << 5;
        }
    }
}