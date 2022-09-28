#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;

    vector <int> ref(n+1);
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        ref[temp]++;
    }

    int count = 0;
    for(int i = 0; i <= n; i++)
    {
        while(ref[i] > d)
        {
            count += ref[i] / d;
            if(ref[i] % d)
            {
                int temp = ref[i] % d;
                ref[i] = ref[i] / d;
                ref[i] += temp;
            }
            else
            {
                ref[i] = ref[i] / d;
            }
        }
    }

    cout << count;
}