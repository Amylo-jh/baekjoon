#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    int max_num = INT32_MIN;

    while(cin >> num)
    {
        if(num < max_num)
        {
            cout << "Bad";
            return 0;
        }
        max_num = num;
    }

    cout << "Good";
}