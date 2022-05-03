#include <iostream>
#include <vector>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) < (b)) ? (b) : (a))

using namespace std;

int main()
{
    int n;
    vector <int> num;

    int decrease_curr = 1;
    int increase_curr = 1;
    int max_value = 1;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }

    for(int i = 0; i < n - 1; i++)
    {
        if(num[i] > num[i+1])
        {
            decrease_curr++;
            increase_curr = 1;
        }
        else if(num[i] < num[i+1])
        {
            decrease_curr = 1;
            increase_curr++;
        }
        else if(num[i] == num[i+1])
        {
            decrease_curr++;
            increase_curr++;
        }

        max_value = max(max_value, decrease_curr);
        max_value = max(max_value, increase_curr);
    }

    cout << max_value;
}