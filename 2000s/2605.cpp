#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> arr;

    for(int i = 0; i < n; i++)
    {
        int seq;
        cin >> seq;

        if(seq == 0)
        {
            arr.push_back(i+1);
        }
        else
        {
            arr.push_back(i+1);
            for(int j = i; j > i-seq; j--)
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}