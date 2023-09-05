#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <double> tab(n+1);
    int end = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> tab[i];
        tab[i] += tab[i-1];
    }
    end = tab[n];
    for(int i = n; i > 0; i--)
    {
        tab[i] = tab[i-1] + (tab[i] - tab[i-1])/2;
    }   

    long long screen_size;
    cin >> screen_size;
    int q;
    cin >> q;


    cout.setf(ios::showpoint);
    cout << fixed;
    cout.precision(2);
    for(int i = 0; i < q; i++)
    {
        int tab_num;
        cin >> tab_num;

        if(tab[tab_num] - screen_size/2 < 0 || end <= screen_size)
        {
            cout << 0.00;
        }
        else if(tab[tab_num] > end - screen_size/2)
        {
            cout << floor(screen_size*100) / 100;
        }
        else
        {
            cout << floor((tab[tab_num] - screen_size/2)*100) / 100;
        }
        cout << "\n";
    }
}