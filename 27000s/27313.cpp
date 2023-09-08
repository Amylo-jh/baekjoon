#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector <int> anime(n);

    for(int i = 0; i < n; i++)
    {
        cin >> anime[i];
    }
    sort(anime.begin(), anime.end());

    int total_anime = 0;
    int index = 0;
    int set_counter = 0;

    while(k > 0 && index < n)
    {
        if(anime[index] <= k)
        {
            index++;
            total_anime++;
            set_counter++;
        }
        else
        {
            break;
        }

        if(set_counter == k)
        {
            k -= anime[index];
            set_counter = 0;
        }
    }

    cout << total_anime;
}