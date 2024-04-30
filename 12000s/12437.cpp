#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t++)
    {
        int month, total_day, week_day;
        cin >> month >> total_day >> week_day;


        int line = 0;
        int remain = 0;
        for(int i = 0; i < month; i++)
        {
            int this_month = total_day + remain;
            line += this_month / week_day;
            if(this_month % week_day)
            {
                line++;
            }
            remain = this_month % week_day;
        }

        cout << "Case #" << t << ": " << line << "\n";
    }
}
