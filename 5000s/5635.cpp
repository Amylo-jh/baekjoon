#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <pair <string, string>> arr(n);
    for(int i = 0; i < n; i++)
    {
        string name;
        string day, month, year;
        string birthday;
        cin >> name >> day >> month >> year;

        if(day.size() == 1)
        {
            day = "0" + day;
        }
        if(month.size() == 1)
        {
            month = "0" + month;
        }
        birthday = year + month + day;
        arr[i] = {birthday, name};
    }
    sort(arr.begin(), arr.end());

    cout << arr[n - 1].second << "\n";
    cout << arr[0].second << "\n";
}