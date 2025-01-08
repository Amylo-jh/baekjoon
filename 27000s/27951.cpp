#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <string> answer(n);
    vector <int> up, down, all;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(temp == 1)
        {
            up.push_back(i);
        }
        else if(temp == 2)
        {
            down.push_back(i);
        }
        else
        {
            all.push_back(i);
        }
    }
    int u_size = up.size();
    int d_size = down.size();
    int a_size = all.size();
    int u, d;
    cin >> u >> d;
    

    if(u > u_size+a_size || d > d_size+a_size)
    {
        cout << "NO";
        return 0;
    }
    u_size--;
    d_size--;
    a_size--;
    
    while(u > 0 && u_size >= 0)
    {
        int idx = up[u_size];
        answer[idx] = "U";
        u--;
        u_size--;
    }
    while(d > 0 && d_size >= 0)
    {
        int idx = down[d_size];
        answer[idx] = "D";
        d--;
        d_size--;
    }
    while(u > 0 && a_size >= 0)
    {
        int idx = all[a_size];
        answer[idx] = "U";
        u--;
        a_size--;
    }
    while(d > 0&& a_size >= 0)
    {
        int idx = all[a_size];
        answer[idx] = "D";
        d--;
        a_size--;
    }

    cout << "YES\n";
    for(string str : answer)
    {
        cout << str;
    }
}