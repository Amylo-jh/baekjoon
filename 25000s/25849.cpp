#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> arr = {1, 5, 10, 20, 50, 100};
    vector <int> money(6);
    int max_money = 0;
    int index = 0;
    
    for(int i = 0; i < 6; i++)
    {
        cin >> money[i];

        if(max_money <= money[i] * arr[i])
        {
            max_money = money[i] * arr[i];
            index = i;
        }
    }

    cout << arr[index];
}