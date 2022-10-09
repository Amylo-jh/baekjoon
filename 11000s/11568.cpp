#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector <int> lis;
    int size_lis = 0;
    int max_value = 0;
    //longest increasing subsequence
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if(size_lis == 0 || max_value < num)
        {
            lis.push_back(num);
            max_value = num;
            size_lis++;
        }
        else
        {
            int pos = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
            lis[pos] = num;

            if(pos == (size_lis-1))
            {
                max_value = num;
            }
        }
    }

    cout << size_lis;    
}