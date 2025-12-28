#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max_num = 1000002;
    vector <int> arr(100001);
    vector <bool> is_prime(max_num, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < max_num; i++)
    {
        if(is_prime[i])
        {
            for(int j = 2; i*j < max_num; j++)
            {
                is_prime[i*j] = false;
            }
        }
    }
    for(int i = 1; i <= 100000; i++)
    {
        arr[i] = arr[i-1];
        bool flag = true;
        int tmp1 = i, tmp2 = 0, mul = 0, rad = 1;
        if(!is_prime[i+1])
        {
            flag = false;
            continue;
        }
        while(i >= 10 && tmp1)
        {
            tmp2 += ((tmp1%10)*rad);
            rad *= 10;
            tmp1 /= 10;
            if(!tmp1)
            {
                continue;
            }
            mul = tmp1*tmp2 + 1;
            if(!is_prime[mul])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            arr[i]++;
        }
    }

    int tc, q;
    cin >> tc;
    while(tc--)
    {
        cin >> q;
        cout << arr[q] << "\n";
    }
}