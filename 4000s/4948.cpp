#include <iostream>
#include <vector>

using namespace std;

void sol(int n)
{
    vector <bool> num = {false, false, true, true}; // 0, 1, 2 ,3

    for(int i = 4; i <= 2*n; i++)
    {
        num.push_back(true);
    }

    for(int i = 2; i <= n; i++)
    {
        if(num[i])
        {
            for(int j = 2; j * i <= 2* n; j++)
            {
                num[i*j] = false;
            }
        }
    }

    int count = 0;
    for(int i = n+1; i <= 2* n; i++)
    {
        if(num[i])
        {
            count++;
        }
    }

    cout << count << endl;

}

int main()
{
    int n = 1;
    while(1)
    {
        cin >> n;
        if(n == 0)
        {
            break;
        }
        sol(n);
    }
}