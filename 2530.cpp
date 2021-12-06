#include <iostream>

using namespace std;

int main()
{
    int hour;
    int min;
    int sec;
    int cook_sec;
    int total_sec;

    cin >> hour >> min >> sec;
    cin >> cook_sec;

    total_sec = hour * 3600 + min * 60 + sec + cook_sec;
    total_sec = total_sec % 86400;
    
    hour = total_sec / 3600;
    total_sec = total_sec - 3600*hour;

    min = total_sec / 60;
    total_sec = total_sec - 60*min;

    sec = total_sec;

    cout << hour << " "<< min << " "<< sec;
}