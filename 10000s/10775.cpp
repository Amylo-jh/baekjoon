#include <iostream>
#include <vector>

using namespace std;

vector <int> port;

int docking(int gi)
{
    if(port[gi] != gi)
    {
        port[gi] = docking(port[gi]);
    }

    int return_value = port[gi];
    port[gi]--;
    return return_value;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int g, p;
    cin >> g >> p;
    port.resize(g+1);
    for(int i = 1; i <= g; i++)
    {
        port[i] = i;
    }

    int counter = 0;
    for(int i = 0; i < p; i++)
    {
        int gi;
        cin >> gi;
        
        int dock = docking(gi);
        if(dock)
        {
            counter++;
        }
        else
        {
            break;
        }
    }

    cout << counter;
}