#include <iostream>
#include <string>

using namespace std;

int main()
{
    int time_a = 0, time_b = 0;
    int temp;
    string str_tmp;
    cin >> temp >> str_tmp;
    time_a += temp;
    time_a *= 60;
    cin >> temp >> str_tmp;
    time_a += temp;
    time_a *= 60;
    cin >> temp;
    time_a += temp;

    cin >> temp >> str_tmp;
    time_b += temp;
    time_b *= 60;
    cin >> temp >> str_tmp;
    time_b += temp;
    time_b *= 60;
    cin >> temp;
    time_b += temp;

    if(time_a > time_b)
    {
        time_b += 86400;
    }

    cout << time_b - time_a;
}