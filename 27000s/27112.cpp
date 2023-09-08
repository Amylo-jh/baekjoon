#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    //due date, estimate day;
    vector <pair <int, int>> work(n);


    for(int i = 0; i < n; i++)
    {
        cin >> work[i].first >> work[i].second;
    }

    sort(work.begin(), work.end());

    int overwork = 0;
    int daywork = 0;

    for(int i = 0; i < n; i++)
    {
        if(work[i].first >= )
    }
}