#include <iostream>

using namespace std;

int main()
{
    int lines;

    cin >> lines;

    for(int k = 0; k < lines; k++)
    {
        for(int i = 0; i < lines-k-1; i++)
        {
            cout << " ";
        }
        for(int j = 0; j <= k; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}