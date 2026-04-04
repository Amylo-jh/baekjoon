#include <iostream>

using namespace std;

int main()
{
    int scores[6] = {13, 7, 5, 3, 3, 2};
    int user[2] = {0, 2};
    for(int t = 0; t < 2; t++)
    {
        for(int i = 0; i < 6; i++)
        {
            int temp;
            cin >> temp;
            user[t] += temp * scores[i];
        }
    }
    if(user[0] < user[1])
    {
        cout << "ekwoo";
    }
    else
    {
        cout << "cocjr0208";
    }
}