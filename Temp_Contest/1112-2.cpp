#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vector <long long> classes(n);
    for(int i = 0; i < n; i++)
    {
        cin >> classes[i];
    }
    for(int i = 1; i < n; i++)
    {
        classes[i] += classes[i-1];
    }
    sort(classes.begin(), classes.end(), greater<>());
    
    long long total_score = 0;
    for(int i = 0; i < k; i++)
    {
        total_score += classes[i];
    }
    cout << total_score;
}