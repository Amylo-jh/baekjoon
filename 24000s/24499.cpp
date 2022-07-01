#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector <int> pie;

    for(int i = 0 ; i < n; i++)
    {
        int temp;
        cin >> temp;
        pie.push_back(temp);
    }

    int max_pie = 0;

    int curr_pie = 0;
    for(int i = 0; i < k; i++)
    {
        curr_pie = curr_pie + pie[i];
    }

    max_pie = curr_pie;

    for(int i = 0; i < n; i++)
    {
        curr_pie = curr_pie - pie[i];
        
        if(i + k >= n)
        {
            curr_pie = curr_pie + pie[k + i - n];
        }
        else
        {
            curr_pie = curr_pie + pie[k+i];
        }

        if(curr_pie > max_pie)
        {
            max_pie = curr_pie;
        }
    }

    cout << max_pie;
}