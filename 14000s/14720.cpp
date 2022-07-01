#include <iostream>

using namespace std;

int main()
{
    int n;
    int drink = 0;

    cin >> n;

    int temp;
    int nextmilk = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        
        if(temp == nextmilk)
        {
            drink++;
            if(nextmilk == 2)
            {
                nextmilk = 0;
            }
            else
            {
                nextmilk++;
            }
        }
    }

    cout << drink;
}