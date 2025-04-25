#include <iostream>

using namespace std;

int main()
{
    int count = 1;
    while(1)
    {
        int r, w, l;
        cin >> r;
        if(!r)
        {
            break;
        }
        cin >> w >> l;

        cout << "Pizza " << count;
        if(4*r*r >= w*w+l*l)
        {
            cout << " fits on the table.\n";
        }
        else
        {
            cout << " does not fit on the table.\n";
        }

        count++;
    }
}