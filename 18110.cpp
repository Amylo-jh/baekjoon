#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> diff;
    int n;
    cin >> n;
    int cut = round(n * 0.15);
    double sum = 0;
    double avg = 0;

    if(n == 0)
    {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        diff.push_back(tmp);
    }

    sort(diff.begin(), diff.end());

    for(int i = cut; i < n - cut; i++)
    {
        sum += diff[i];
    }

    avg = sum / (n - (cut*2));

    cout << round(avg);
}