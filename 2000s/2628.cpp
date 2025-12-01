#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector <int> arrn = {0};
    vector <int> arrm = {0};
    for(int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a)
        {
            arrn.push_back(b);
        }
        else
        {
            arrm.push_back(b);
        }
    }
    arrm.push_back(m);
    arrn.push_back(n);
    sort(arrn.begin(), arrn.end());
    sort(arrm.begin(), arrm.end());

    int maxn = 0, maxm = 0;
    for(int i = 1; i < arrn.size(); i++)
    {
        maxn = max(maxn, arrn[i] - arrn[i-1]);
    }
    for(int i = 1; i < arrm.size(); i++)
    {
        maxm = max(maxm, arrm[i] - arrm[i-1]);
    }
    cout << maxn * maxm;
    
}