#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int wait = 0;
    int music = 0;
    
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        
        if(b <= music)
        {
            music -= b;
            music += a;
        }
        else
        {
            b -= music;
            wait += b;
            music = a;
        }
    }

    cout << wait;
}