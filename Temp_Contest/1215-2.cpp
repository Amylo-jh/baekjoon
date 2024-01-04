#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <int> arr(1001);
    int count = 0;
    int jinju = 0;
    for(int i = 0; i < n; i++)
    {
        string str;
        long long price;
        cin >> str >> price;
        if(str == "jinju")
        {
            jinju = price;
        }
        else
        {
            if(price > 1000)
            {
                count++;
            }
            else
            {
                arr[price]++;
            }
        }
    }
    for(int i = jinju+1; i <= 1000; i++)
    {
        count += arr[i];
    }

    cout << jinju << "\n" << count;
}