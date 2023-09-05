#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> arr(4);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int g, c, p;
        cin >> g >> c >> p;
        if(g == 1)
        {
            arr[3]++;
        }
        else
        {
            if(c == 1 || c == 2)
            {
                arr[0]++;
            }
            else if(c == 3)
            {
                arr[1]++;
            }
            else if(c == 4)
            {
                arr[2]++;
            }
        }
    }

    for(int i = 0; i < 4; i++)
    {
        cout << arr[i] << "\n";
    }
}