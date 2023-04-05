#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <vector <bool>> area(100);

    int n;
    cin >> n;

    for(int i = 0; i < 100; i++)
    {
        area[i].resize(100);
    }

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        for(int j = a; j < a+10; j++)
        {
            for(int k = b; k < b+10; k++)
            {
                area[j][k] = true;
            }
        }
    }

    int count = 0;
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            if(area[i][j])
            {
                count++;
            }
        }
    }

    cout << count;
}