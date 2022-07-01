#include <iostream>

using namespace std;

int main()
{
    int n;
    int level=1;
    int total=0;

    cin >> n;
    
    if(n > 1)
    {
        total = 1;
        while(total < n)
        {
            level++;
            total = total + (level-1)*6;
        }
        cout << level;
    }
    else
    {
        cout << "1";
    }   
}