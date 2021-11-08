#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int> x;
    vector<int> y;
    int q1 = 0, q2 = 0, q3 = 0, q4 = 0, axis = 0;

    cin >> n;

    int tmp1, tmp2;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &tmp1, &tmp2);
        x.push_back(tmp1);
        y.push_back(tmp2);
    }

    for (int i = 0; i < n; i++)
    {
        if(x[i] > 0)
        {
            if(y[i] > 0)
            {
                q1++;
                continue;
            }
            if(y[i] < 0)
            {
                q4++;
                continue;
            }
            else
            {
                axis++;
                continue;
            }
        }

        if(x[i] < 0)
        {
            if(y[i] > 0)
            {
                q2++;
                continue;
            }
            if(y[i] < 0)
            {
                q3++;
                continue;
            }
            else
            {
                axis++;
                continue;
            }
        }
        else
        {
            axis++;
            continue;
        }
    }

    cout << "Q1: " << q1 << endl;
    cout << "Q2: " << q2 << endl;
    cout << "Q3: " << q3 << endl;
    cout << "Q4: " << q4 << endl;
    cout << "AXIS: " << axis << endl;
}
