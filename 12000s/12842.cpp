#include <iostream>

using namespace std;

int main()
{
    int bread, diff;
    int peoples;
    cin >> bread >> diff >> peoples;
    
    bread -= diff;
    int people[peoples];

    for(int i = 0; i < peoples; i++)
    {
        cin >> people[i];
    }

    int time = 0;
    int index = 0;
    while(bread)
    {
        for(int i = 0; i < peoples; i++)
        {
            if(time % people[i] == 0)
            {
                bread--;
                index = i;
            }

            if(bread == 0)
            {
                break;
            }
        }
        time++;
    }

    cout << index + 1;
}