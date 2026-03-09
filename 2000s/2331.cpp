#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int calc(int a, int p)
{
    int sum = 0;
    while(a)
    {
        int n = a%10;
        n = pow(n, p);
        sum += n;
        a /= 10;
    }
    return sum;
}

int main()
{
    int a, p;
    cin >> a >> p;
    vector <bool> is_used(1000001);
    vector <int> arr = {a};
    is_used[a] = true;
    while(1)
    {
        int next = calc(a, p);
        if(is_used[next])
        {
            int count = 0;
            for(int i : arr)
            {
                if(i == next)
                {
                    break;
                }
                count++;
            }
            cout << count;
            break;
        }
        is_used[next] = true;
        arr.push_back(next);
        a = next;
    }
}