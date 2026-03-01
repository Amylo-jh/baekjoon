#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a(10);
    vector<int> b(10);
    int last = 0, score_a = 0, score_b = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < 10; i++)
    {
        if (a[i] > b[i])
        {
            last = 1;
            score_a += 3;
        }
        else if (b[i] > a[i])
        {
            last = 2;
            score_b += 3;
        }
        else
        {
            score_a++;
            score_b++;
        }
    }
    cout << score_a << " " << score_b << "\n";
    if (score_a > score_b)
    {
        cout << "A";
    }
    else if (score_b > score_a)
    {
        cout << "B";
    }
    else if (last == 0)
    {
        cout << "D";
    }
    else if (last == 1)
    {
        cout << "A";
    }
    else if (last == 2)
    {
        cout << "B";
    }
}