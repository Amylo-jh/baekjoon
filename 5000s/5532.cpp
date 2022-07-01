#include <iostream>

using namespace std;

int main()
{
    int day;
    int korean;
    int math;
    int kpd;
    int mpd;
    int k_day;
    int m_day;

    cin >> day >> korean >> math >> kpd >> mpd;

    k_day = korean / kpd;
    m_day = math / mpd;

    if(korean % kpd)
    {
        k_day++;
    }
    if(math % mpd)
    {
        m_day++;
    }

    cout << day - max(k_day, m_day);
}