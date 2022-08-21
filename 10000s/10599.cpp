#include <iostream>

using namespace std;

int main()
{
    int age[4];
    while(true)
    {
        bool flag = true;
        for(int i = 0; i < 4; i++)
        {
            cin >> age[i];
        }
        
        for(int i = 0; i < 4; i++)
        {
            if(age[i] != 0)
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            break;
        }
        
        cout << age[2] - age[1] << " ";
        cout << age[3] - age[0] << endl;
    }
}