#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    bool sample_tc = true;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        if(a != b)
        {
            sample_tc = false;
        }
    }

    bool system_tc = true;
    for(int i = 0 ; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        
        if(a != b)
        {
            system_tc = false;
        }
    }

    if(sample_tc && system_tc)
    {
        cout << "Accepted";
    }
    else if(!sample_tc)
    {
        cout << "Wrong Answer";
    }
    else if(!system_tc)
    {
        cout << "Why Wrong!!!";
    }
}