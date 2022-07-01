#include <iostream>

using namespace std;

int main()
{
    int stars;

    cin >> stars;

    for(int i = 0; i < stars; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for(int k = (stars-i)*2-1; k > 0; k--)
        {
            cout << "*";
        }
        cout << endl;
    }
}