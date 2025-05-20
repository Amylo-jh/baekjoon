#include <iostream>

using namespace std;

int main()
{
    cout << fixed;
    cout.precision(2);
    while(1)
    {
        double d;
        cin >> d;
        if(d < 0)
        {
            break;
        }
        
        cout << "Objects weighing ";
        cout << d;
        cout << " on Earth will weigh ";
        cout << d*0.167;
        cout << " on the moon.\n"; 
    }
}