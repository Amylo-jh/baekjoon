#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector <int> arr_a(n);
    vector <int> arr_c(n);
    set <int> set_b;

    for(int i = 0; i < n; i++)
    {
        cin >> arr_a[i];
    }
    sort(arr_a.begin(), arr_a.end());

    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        set_b.insert(temp);
    }

    int counter = 0;
    for(int i = 0; i < n; i++)
    {
        if(set_b.find(arr_a[i]) == set_b.end())
        {
            arr_c[counter] = arr_a[i];
            counter++;
        }
    }

    cout << counter << "\n";
    for(int i = 0; i < counter; i++)
    {
        cout << arr_c[i] << " ";
    }
}