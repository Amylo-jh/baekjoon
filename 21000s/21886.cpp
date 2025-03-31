#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> arr = {100, 100, 200, 200, 300, 300, 400, 400, 500};
    int sum = 0;
    bool flag = false;
    for(int i = 0; i < 9; i++)
    {
        int temp;
        cin >> temp;
        if(temp <= arr[i])
        {
            sum += temp;
        }
        else
        {
            cout << "hacker";
            return 0;
        }
    }

    if(sum >= 100)
    {
        cout << "draw";
    }
    else
    {
        cout << "none";
    }
}