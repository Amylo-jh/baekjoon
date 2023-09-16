#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int max_stric = 0;
    int curr_stric = 0;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(temp)
        {
            curr_stric++;
        }
        else
        {
            curr_stric = 0;
        }
        max_stric = max(max_stric, curr_stric);
    }

    cout << max_stric;
}