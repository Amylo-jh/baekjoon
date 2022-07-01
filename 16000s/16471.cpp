#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector <int> sacho;
    vector <int> jueon;
    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        jueon.push_back(temp);
    }
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        sacho.push_back(temp);
    }

    sort(jueon.begin(), jueon.end(), greater<>());
    sort(sacho.begin(), sacho.end(), greater<>());


    int score = 0;

    int index_sacho = 0;
    int index_jueon = 0;
    
    while(index_jueon < n)
    {
        if(jueon[index_jueon] >= sacho[index_sacho])
        {
            index_jueon++;
            continue;
        }
        else if(jueon[index_jueon] < sacho[index_sacho])
        {
            score++;
            index_jueon++;
            index_sacho++;
        }
    }

    if(score >= (n + 1)/2)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

}