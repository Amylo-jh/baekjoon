#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    vector <double> curr(4, 0.25);
    vector <double> next(4, 0);
    vector <vector <pair <int, double>>> nextshop(4);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        char a, b;
        double c;
        cin >> a >> b >> c;
        nextshop[a - 'A'].push_back({b - 'A', c});
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(auto k : nextshop[j])
            {
                next[k.first] += curr[j] * k.second;
            }
        }
        curr = next;
        next = vector <double>(4, 0);
    }

    cout << fixed;
    cout.precision(10);
    for(int i = 0; i < 4; i++)
    {
        cout << curr[i]*100 << "\n";
    }
}