#include <iostream>

using namespace std;

int main()
{
    int n;
    int count = 0;

    cin >> n;
    for(int i = 0; i < 5; i++)
    {
        int num;
        cin >> num;

        if(num == n)
        {
            count++;
        }
    }

    cout << count;
}