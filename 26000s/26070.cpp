#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <long long> req(3);
    vector <long long> ticket(3);
    
    cin >> req[0] >> req[1] >> req[2];
    cin >> ticket[0] >> ticket[1] >> ticket[2];
    
    long long count = 0;
    for(int i = 0; i < 3; i++)
    {
        if(req[i] <= ticket[i])
        {
            count += req[i];
            ticket[i] -= req[i];
            req[i] = 0;
        }
        else
        {
            count += ticket[i];
            req[i] -= ticket[i];
            ticket[i] = 0;
        }

        int next_tic = ticket[i] / 3;
        ticket[i] -= next_tic * 3;
        if(i == 2)
        {
            ticket[0] += next_tic;
        }
        else
        {
            ticket[i+1] += next_tic;
        }
    }

    if(req[0] <= ticket[0])
    {
        count += req[0];
        ticket[0] -= req[0];
        req[0] = 0;
    }
    else
    {
        count += ticket[0];
        req[0] -= ticket[0];
        ticket[0] = 0;
    }

    cout << count;
}