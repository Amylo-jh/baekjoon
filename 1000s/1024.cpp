#include <iostream>

using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;
    bool possible = true;

    int middlevalue = 0;

    for(l; l <= 100; l++)
    {
        if(l % 2)
        {
            if(n % l == 0)
            {
                middlevalue = n / l;
                break;
            }
        }
        else
        {
            if(n % l == l / 2)
            {
                middlevalue = n / l;
                break;
            }
        }
    }

    if(l > 100 || middlevalue - ((l-1) / 2) < 0)
    {
        cout << "-1";
        return 0;
    }

    int i = middlevalue - ((l-1) / 2);
    for(i; i <= middlevalue + ((l-1) / 2); i++)
    {
        cout << i << " ";
    }

    if(l % 2 == 0)
    {
        //i++;
        cout << i;
    }
}