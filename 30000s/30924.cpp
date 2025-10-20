#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(0));
    int a = 10000, b = 9999, count = 9999, tmp;
    vector <bool> aa(10001), bb(10001);
    aa[0] = bb[0] = true;
    while(count--)
    {
        int i = rand() % 10001;
        if(!aa[i])
        {
            cout << "? A " << i << endl;
            cin >> tmp;
            if(tmp)
            {
                a = i;
                break;
            }
            aa[i] = true;
        }
        else
        {
            count++;
        }
    }
    count = 9998;
    while(count--)
    {
        int i = rand() % 10001;
        if(!bb[i])
        {
            cout << "? B " << i << endl;
            cin >> tmp;
            if(tmp)
            {
                b = i;
                break;
            }
            bb[i] = true;
        }
        else
        {
            count++;
        }
    }

    cout << "! " << a+b;
}