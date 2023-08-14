#include <iostream>
#include <vector>

using namespace std;

vector <bool> number;
vector <int> prime;

int main()
{
    number.resize(2000000);
    number.assign(2000000, true);

    number[0] = false;
    number[1] = false;
    for(int i = 2; i <= 2000000; i++)
    {
        if(number[i])
        {
            for(int j = 2; j*i <= 2000000; j++)
            {
                number[i*j] = false;
            }
        }
    }
    for(int i = 0; i <= 2000000; i++)
    {
        if(number[i])
        {
            prime.push_back(i);
        }
    }

    int n;
    cin >> n;
    bool flag = true;
    vector <int> num(n);
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    vector <int> nums((n*(n-1))/2);
    int counter = 0;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            nums[counter] = num[i]+num[j];
            counter++;
        }
    }

    cout << "done";



    
}