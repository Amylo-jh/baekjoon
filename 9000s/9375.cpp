#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        map <string, int> clothes;
        int cloth_count;
        cin >> cloth_count;

        for(int i = 0; i < cloth_count; i++)
        {
            string tmp, cloth_category;
            cin >> tmp >> cloth_category;

            if(auto [iterator, success] = clothes.insert({cloth_category, 1}) ; success == false)
            {
                iterator->second++;
            }
        }

        int total_case = 1;
        for(auto iter : clothes)
        {
            total_case *= (iter.second + 1);
        }

        cout << total_case - 1 << "\n";
    }
}