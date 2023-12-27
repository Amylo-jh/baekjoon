#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector <string> arr(5);
    int max_length = 0;
    for(int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        max_length = max(max_length, int(arr[i].length()));
    }


    for(int i = 0; i < max_length; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(i >= arr[j].length())
            {
                continue;
            }
            else
            {
                cout << arr[j][i];
            }
        }
    }
}