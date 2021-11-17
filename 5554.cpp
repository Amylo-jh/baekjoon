#include <iostream>

using namespace std;

int main()
{
    int time[4];
    int total = 0;
    int min = 0;
    int sec = 0;

    for(int i = 0; i < 4; i++)
    {
        cin >> time[i];
        total = total + time[i];
    }
    min = total / 60;
    sec = total - min*60;

    cout << min << endl;
    cout << sec;


}