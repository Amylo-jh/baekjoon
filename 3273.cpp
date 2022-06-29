#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <bool> num;
    num.reserve(1000001);

    for(int i = 0; i <= 1000000; i++)
    {
        num.push_back(false);
    }

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        num[number] = true;
    }

    int x;
    cin >> x;

    int count = 0;

    for(int i = 1; i <= min(x/2, 1000000); i++)
    {
        if(num[i] && x - i <= 1000000 && num[x-i])
        {
            if(num[x-i] && (i != x-i) )
            {
                count++;
            }
        }
    }

    cout << count;
}