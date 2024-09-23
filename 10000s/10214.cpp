#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int arr[2]= {0, 0};

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                int temp;
                cin >> temp;

                arr[j] += temp;
            }
        }

        if(arr[0] > arr[1])
        {
            cout << "Yonsei\n";
        }
        else if(arr[0] < arr[1])
        {
            cout << "Korea\n";
        }
        else
        {
            cout << "Draw\n";
        }
    }
}