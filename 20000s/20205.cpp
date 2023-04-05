#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int n, k;
    cin >> n >> k;

    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        
        int counter = 0;
        for(int h = 0; h < k; h++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << arr[j] << " ";
                counter++;
                j--;
                if(counter == k)
                {
                    counter = 0;
                    j++;
                }
            }
            cout << "\n";
        }
    }
}