#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        int seq;
        cin >> seq;
        seq = seq * 100 / n;

        if(seq <= 4)
        {
            cout << 1;
        }
        else if(seq <= 11)
        {
            cout << 2;
        }
        else if(seq <= 23)
        {
            cout << 3;
        }
        else if(seq <= 40)
        {
            cout << 4;
        }
        else if(seq <= 60)
        {
            cout << 5;
        }
        else if(seq <= 77)
        {
            cout << 6;
        }
        else if(seq <= 89)
        {
            cout << 7;
        }
        else if(seq <= 96)
        {
            cout << 8;
        }
        else if(seq <= 100)
        {
            cout << 9;
        }
        cout << " ";
    }
}