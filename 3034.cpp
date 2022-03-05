#include <iostream>

using namespace std;

int main()
{
    int n, w, h;
    cin >> n >> w >> h;

    int total = w * w + h * h;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        temp = temp * temp;
        if(total >= temp)
        {
            cout << "DA" << endl;
        }
        else
        {
            cout << "NE" << endl;
        }
    }
}