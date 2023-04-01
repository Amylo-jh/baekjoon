#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> vote(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vote[i];
    }

    bool flag = true;
    int count = 0;
    while(flag)
    {
        flag = false;
        int index = 0;
        for(int i = 1; i < n; i++)
        {
            if(vote[i] >= vote[index])
            {
                index = i;
                flag = true;
                continue;
            }
        }

        if(!flag)
        {
            break;
        }
        vote[index]--;
        vote[0]++;
        count++;
    }

    cout << count;
}