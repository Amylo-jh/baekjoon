#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int count = 0;
    int stress = 0;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        stress += temp;
        stress = max(0, stress);

        if(stress >= m)
        {
            count++;
        }
    }

    cout << count;
}